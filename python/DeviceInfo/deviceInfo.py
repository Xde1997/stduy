import wmi
import platform
import subprocess
import json
from psutil import net_if_addrs


def GetDeviceInfo():
    json_data = {}
    sysstr = platform.system()
    if(sysstr == "Windows"):
        json_data["cpuid"] = getCpuidForWindows()
        json_data["mac"] = getMac()
        json_data["baseboardid"] = getBaseboardIdForWindows()
    elif(sysstr == "Linux"):
        json_data["cpuid"] = getCpuidForLinux()
        json_data["mac"] = getMac()
        json_data["baseboardid"] = getBaseboardIdForLinux()
    else:
        print("Other System tasks")
    return json.dumps(json_data)


def getCpuidForWindows():
    cpus = []
    for cpu in wmi.WMI().Win32_Processor():
        var = cpu.ProcessorId.strip()
        if cpus.count(var) == 0:
            cpus.append(var)
    return cpus


def getCpuidForLinux():
    p = subprocess.Popen(["sudo dmidecode -t 4 | grep ID"], shell=True,
                         stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    data = p.stdout
    lines = []
    while True:
        line = str(data.readline(), encoding="utf-8")
        if line == '\n':
            break
        if line:
            d = dict([line.strip().split(': ')])
            lines.append(d)
        else:
            break
    return lines


# linux和windows通用
def getMac():
    listMac = []
    for k, v in net_if_addrs().items():
        for item in v:
            address = item[1]
            if len(address) == 17:
                address = str(address).replace(':', '-')
                if listMac.count(address) == 0:
                    listMac.append(address)
    return listMac


def getBaseboardIdForWindows():
    baseboards = []
    for baseboard in wmi.WMI().Win32_BaseBoard():
        var = baseboard.SerialNumber.strip()
        if baseboards.count(var) == 0:
            baseboards.append(var)
    if len(baseboards) == 0:
        return ""
    return baseboards[0]


def getBaseboardIdForLinux():
    p = subprocess.Popen(["sudo dmidecode -t 2 | grep Serial"], shell=True,
                         stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    data = p.stdout
    lines = []
    while True:
        line = str(data.readline(), encoding="utf-8")
        if line == '\n':
            break
        if line:
            d = dict([line.strip().split(': ')])
            lines.append(d)
        else:
            break
    return lines[0]

from tkinter import *
from PIL import ImageTk, Image
import json
import os
import deviceInfo
from Crypto.Cipher import AES
import base64
# from Crypto.Util.Padding import pad, unpad

# adjopwabdihawoic
p = 'diwhiodahoidhwioadjopwabdihawoic'
BLOCK_SIZE = len(p)  # Bytes


def pad(s: bytes): return s+(BLOCK_SIZE - len(s) %
                             BLOCK_SIZE)*chr(BLOCK_SIZE - len(s) % BLOCK_SIZE).encode()


def unpad(s): return s[:-ord(s[len(s)-1:])]


class Application(Frame):
    def __init__(self, master=None):
        self.frame = Frame.__init__(self, master=master)
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        frame_t = Frame(self.frame)  # 第二层frame，左frame，长在主frame上
        frame_b = Frame(self.frame)  # 第二层frame，右frame，长在主frame上
        frame_t.pack(side='top')
        frame_b.pack(side='bottom')
        self.helloLabel = Label(frame_t, text='请输入购买机构:',  font=(8))
        # self.helloLabel.place(x=130, y=100, anchor='nw')
        self.helloLabel.pack(padx=5, pady=40, side=LEFT)
        self.helloEntry = Entry(frame_t, show=None, width=30,
                                exportselection=0, font=(8))
        # self.helloEntry.place(x=220, y=100, anchor='nw')
        self.helloEntry.pack(padx=10, pady=40, side=LEFT)
        self.quitButton = Button(
            frame_b, text='开始', command=self.buttonCommand, width=10)
        # self.quitButton.place(x=400, y=200, anchor='nw')
        self.quitButton.pack(padx=5, pady=40, side=RIGHT)

        # img_open = Image.open('caxa.webp')
        # img_png = ImageTk.PhotoImage(img_open)
        # self.label_img = Label(frame_b, image=img_png)
        # self.label_img.pack(padx=5, pady=40, side=LEFT)

    def buttonCommand(self):
        strdeviceInfo = deviceInfo.GetDeviceInfo()
        organization = self.helloEntry.get()
        strDeviceJson = json.loads(strdeviceInfo)
        strDeviceJson["organization"] = str(organization)
        strdeviceInfo = json.dumps(strDeviceJson)

        i = strAesEncrypt(p, strdeviceInfo)
        createFile(i)
        strAesDecrypt(p, i)


def createFile(info: str):
    path = os.getcwd()
    filepath = path+"\\fingerPrint.dat"
    file = open(filepath, 'w')
    file.write(info)
    file.close()


def strAesEncrypt(key: str, info: str):
    # key = key.encode('utf8')
    cipher = AES.new(key.encode("utf8"), AES.MODE_ECB)
    info = info.encode()
    encryptInfo = pad(info)
    result = cipher.encrypt(encryptInfo)
    encodestrs = base64.b64encode(result)
    enctext = encodestrs.decode('utf8')
    return enctext


def strAesDecrypt(key: str, enctext: str):
    decoderstr = base64.b64decode(enctext)
    cipher = AES.new(key.encode("utf8"), AES.MODE_ECB)
    result = cipher.decrypt(decoderstr).decode("utf8")
    print(result)


if __name__ == "__main__":
    app = Application()
    # 设置窗口标题:
    app.master.title('CAXA设备指纹提取程序')

    app.master.geometry('500x300')
    app.master.resizable(0, 0)
    # 主消息循环:
    app.mainloop()

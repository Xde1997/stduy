import os

import Crypto
from Crypto.Cipher import AES, PKCS1_v1_5
import base64
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_v1_5 as PKCS1_cipher
import hashlib

listdir = []


def unpad(s):
    return s[:-ord(s[len(s) - 1:])]


def readTemplateProducts():
    filepath = os.path.abspath(os.curdir) + "\\template\\"
    global listdir
    listdir = os.listdir(filepath)
    listdir.reverse()
    return listdir


def strAesDecrypt(key: str, enctext: str) -> str:
    decoderstr = base64.b64decode(enctext)
    cipher = AES.new(key.encode("utf8"), AES.MODE_ECB)
    result = unpad(cipher.decrypt(decoderstr)).decode("utf8")
    return result


def encrypt_data(key: str, msg: str):
    key = RSA.importKey(key)
    cipher = PKCS1_cipher.new(key)

    hlib = hashlib.md5()
    b = msg.encode(encoding='utf-8')
    hlib.update(b)
    msg = hlib.hexdigest()
    encrypt_text = base64.b64encode(cipher.encrypt(bytes(msg.encode("utf8"))))
    return encrypt_text.decode('utf-8')


def decrypt_data(key: str, encrypt_msg: str):
    key = RSA.importKey(key)
    cipher = PKCS1_cipher.new(key)
    back_text = cipher.decrypt(base64.b64decode(encrypt_msg), 0)
    return back_text.decode('utf-8')


def rsa_long_encrypt(pub_key_str, msg, length=100):
    """
    单次加密串的长度最大为 (key_size/8)-11
    1024bit的证书用100， 2048bit的证书用 200
    """
    pubobj = RSA.importKey(pub_key_str)
    pubobj = PKCS1_v1_5.new(pubobj)
    res = []
    for i in range(0, len(msg), length):
        res.append(pubobj.encrypt(msg[i:i + length]))
    return "".join(res)


def rsa_long_decrypt(priv_key_str, msg, length=128):
    """
    1024bit的证书用128，2048bit证书用256位
    """
    privobj = RSA.importKey(priv_key_str)
    privobj = PKCS1_v1_5.new(privobj)
    res = []
    for i in range(0, len(msg), length):
        res.append(privobj.decrypt(msg[i:i + length], 'xyz'))
    return "".join(res)


def get_max_length(rsa_key, encrypt=True):
    """加密内容过长时 需要分段加密 换算每一段的长度.
        :param rsa_key: 钥匙.
        :param encrypt: 是否是加密.
    """
    blocksize = Crypto.Util.number.size(rsa_key.n) / 8
    reserve_size = 11  # 预留位为11
    if not encrypt:  # 解密时不需要考虑预留位
        reserve_size = 0
    maxlength = blocksize - reserve_size
    return maxlength


# 加密 支付方公钥
def encrypt_by_public_key(key, encrypt_message):
    """使用公钥加密.
        :param encrypt_message: 需要加密的内容.
        加密之后需要对接过进行base64转码
    """
    encrypt_result = b''
    key = RSA.importKey(key)
    max_length = int(get_max_length(key))
    cipher = PKCS1_v1_5.new(key)
    while encrypt_message:
        input_data = encrypt_message[:max_length]
        encrypt_message = encrypt_message[max_length:]
        out_data = cipher.encrypt(input_data.encode(encoding='utf-8'))
        encrypt_result += out_data
    encrypt_result = base64.b64encode(encrypt_result)
    return encrypt_result.decode('utf-8')


# 加密 支付方私钥
def encrypt_by_private_key(key, encrypt_message):
    """使用私钥加密.
        :param encrypt_message: 需要加密的内容.
        加密之后需要对接过进行base64转码
    """
    encrypt_result = b""
    key = RSA.importKey(key)
    max_length = int(get_max_length(key))
    cipher = PKCS1_v1_5.new(key)
    while encrypt_message:
        input_data = encrypt_message[:max_length]
        encrypt_message = encrypt_message[max_length:]
        out_data = cipher.encrypt(input_data.encode(
            encoding='utf-8').strip() + b"\n")
        encrypt_result += out_data
    encrypt_result = base64.b64encode(encrypt_result)
    return encrypt_result


def decrypt_by_public_key(key, decrypt_message):
    """使用公钥解密.
        :param decrypt_message: 需要解密的内容.
        解密之后的内容直接是字符串，不需要在进行转义
    """
    decrypt_result = b""
    max_length = get_max_length(key, False)
    decrypt_message = base64.b64decode(decrypt_message)
    cipher = PKCS1_v1_5.new(key)
    while decrypt_message:
        input_data = decrypt_message[:max_length]
        decrypt_message = decrypt_message[max_length:]
        out_data = cipher.decrypt(input_data.encode(encoding='utf-8'), '')
        decrypt_result += out_data
    return decrypt_result


def decrypt_by_private_key(key, decrypt_message):
    """使用私钥解密.
        :param decrypt_message: 需要解密的内容.
        解密之后的内容直接是字符串，不需要在进行转义
    """
    decrypt_result = b""
    max_length = int(get_max_length(key, False))
    decrypt_message = base64.b64decode(decrypt_message)
    cipher = PKCS1_v1_5.new(key)
    while decrypt_message:
        input_data = decrypt_message[:max_length]
        decrypt_message = decrypt_message[max_length:]
        out_data = cipher.decrypt(input_data, '')
        decrypt_result += str(out_data).encode(encoding='utf-8').strip() + b"\n"
    return decrypt_result


def signature(license: map, key: str):
    encrypt = ""
    # for key in listKeys:
    #     encrypt
    encrypt += license["application"]
    encrypt += str(license["rivision"])
    modules = license["modules"]
    for module in modules:
        encrypt += module["name"]
        if "limit" in module:
            if module["limit"] >= 0:
                encrypt += str(module["limit"])
        if "authorized" in module:
            encrypt += str(module["authorized"])
        encrypt += module["expired_time"]
    fingerprint = license["fingerprint"]
    for cpu in fingerprint["cpuid"]:
        encrypt += cpu
    for mac in fingerprint["mac"]:
        encrypt += mac
    encrypt += fingerprint["baseboardid"]
    md5 = hashlib.md5()
    md5.update(encrypt.encode(encoding='utf-8'))
    md5encrypt = md5.hexdigest()
    key = RSA.importKey(key)
    cipher = PKCS1_cipher.new(key)
    encrypt_text = base64.b64encode(
        cipher.encrypt(bytes(md5encrypt.encode("utf8"))))

    license["signature"] = encrypt_text.decode()

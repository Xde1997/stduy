package main

import (
	"crypto/rand"
	"crypto/rsa"
	"crypto/x509"
	"encoding/pem"
	"errors"
	"fmt"
	"os"
)

var a = `-----BEGIN PUBLIC KEY-----
MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDDk/5fKtTbl4jikigyakBdU0fM
uWJrn7zbsiw6l/hckxrVwrEfVjRMVbWXV3MU7BRGw76fDhBW3Ct+w34ArCj/EkDj
zQ7bwp3Gc59B+dxaGjSOlYvCkYKjafFv1WM7eW3mSv8vBgy2O7n03nzPm+sOakYq
rNb+mxQoUL04nJ3HnwIDAQAB
-----END PUBLIC KEY-----
`

// 加密
func RsaEncrypt(str []byte) ([]byte, error) {
	block, _ := pem.Decode([]byte(a))
	if block == nil {
		return nil, errors.New("public key error!")
	}
	//加密PKCS1格式的公钥
	pubk, err := x509.ParsePKIXPublicKey(block.Bytes)
	if err != nil {
		return nil, err
	}
	// 加密
	return rsa.EncryptPKCS1v15(rand.Reader, pubk.(*rsa.PublicKey), str)
}

func main() {
	b := "caxa"
	data, _ := RsaEncrypt([]byte(b))
	fmt.Println(string(data))
	file, _ := os.Create(".\\rsa.txt")
	file.Write(data)
	//newdata := base64.StdEncoding.EncodeToString(data)
	//fmt.Println((newdata))
}

/**
SDK依赖第三方包，mahonia（字符编码处理）,uuid（生成uuid），需要预先获取依赖包
go env -w GO111MODULE=on
go get -u "github.com/axgle/mahonia"
go get -u "github.com/satori/go.uuid"
**/
package main

import (
	"fmt"
	"showSdk/normalRequest"
)

func main() {
	showapi_appid := "xdp"          //要替换成自己的
	showapi_sign := "xiedepeng1997" //要替换成自己的
	res := normalRequest.ShowapiRequest("http://route.showapi.com/1797-1", showapi_appid, showapi_sign)
	res.AddTextPara("page", "0")
	res.AddTextPara("url", "MzkyODE5NjU2Mw==")
	fmt.Println(res.Post())
}

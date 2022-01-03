package main

import (
	"fmt"
	"time"
)

func Foo() {
	fmt.Println("打印1")
}

func main() {
	go Foo()
	fmt.Println("打印3")
	time.Sleep(1000 * time.Second)
}

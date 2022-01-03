package main

import (
	"log"
	"net"
	"time"
)

func main() {
	c, err := net.Dial("tcp", "localhost:8080")
	if err != nil {
		log.Fatalf("Error to open tcp connection:%s", err)
	}
	defer c.Close()

	log.Printf("TCP Session open")
	b := []byte("Hi,gopher?")
	_, err = c.Write(b)
	if err != nil {
		log.Fatalf("Error writing TCP session:%s", err)
	}

	go func() {
		<-time.After(time.Duration(10) * time.Second)
		defer c.Close()
	}()

	for {
		d := make([]byte, 10)
		_, err := c.Read(d)
		if err != nil {
			log.Fatalf("Error reading tcp session:%s", err)
		}
		log.Printf("reading data from server:%s\n", string(d))
	}
}

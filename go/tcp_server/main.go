package main

import (
	"log"
	"net"
)

func main() {
	l, err := net.Listen("tcp", ":8080")
	if err != nil {
		log.Fatalf("Error listener returned: %s", err)
	}
	defer l.Close()

	for {
		c, err := l.Accept()
		if err != nil {
			log.Fatalf("Error to accept new connection:%s", err)
		}

		go func() {
			log.Printf("Tcp session open")
			defer c.Close()

			for {
				d := make([]byte, 100)

				_, err := c.Read(d)
				if err != nil {
					log.Printf("Error reading tcp session: %s", err)
					break
				}
				log.Printf("reading data from client:%s\n", string(d))

				_, err = c.Write(d)
				if err != nil {
					log.Printf("Error writing TCP session:%s", err)
					break
				}
			}
		}()
	}
}

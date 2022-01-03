package main

import "fmt"

func add(a, b int) int {
	sum := a + b
	return sum
}

func main() {
	sum := add(1, 2)
	fmt.Println(sum)
	a := new(int)
	fmt.Println(a, &sum)
}

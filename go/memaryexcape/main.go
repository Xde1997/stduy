package main

func testNew() {
	t := new(int)
	*t = 1
}

func main() {
	testNew()
}

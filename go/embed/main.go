package main

import (
	"embed"
	"fmt"
)

var (
	// Version string = strings.TrimSpace(version)

	//go:embed websites
	version embed.FS
)

func main() {
	fmt.Printf("Version %q\n", version)
}

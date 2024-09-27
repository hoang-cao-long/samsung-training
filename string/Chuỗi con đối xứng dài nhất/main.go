package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	stdin, err := os.OpenFile("input.txt", os.O_RDONLY|os.O_CREATE, 0666)
	if err != nil {
		log.Fatal(err)
	}
	os.Stdin = stdin

	stdout, err := os.OpenFile("output.txt", os.O_WRONLY|os.O_CREATE|os.O_TRUNC, 0666)
	if err != nil {
		log.Fatal(err)
	}
	os.Stdout = stdout

	// Your code here
	var T int
	fmt.Scanf("%d", &T)
	fmt.Println(T)
	for i := 0; i < T; i++ {
		var N string
		fmt.Scanf("%s", &N)
		fmt.Println(N)
	}

	// fmt.Println("out")
	return

}

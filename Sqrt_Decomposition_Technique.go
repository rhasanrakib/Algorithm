package main

import (
	"fmt"
	"log"
	"math"
	"os"
)

var arr [10]int
var block [10]int
var blk_sz int

func update(index int, val int) {
	blk_num := index % blk_sz
	block[blk_num] = block[blk_num] - arr[index] + val
	arr[index] = val
}
func preprocessor(arr [10]int, n int) {
	blk_sz = int(math.Sqrt(float64(n)))
	blk_num := -1

	for i := 0; i < n; i++ {
		if i%blk_sz == 0 {
			blk_num++
		}
		block[blk_num] += arr[i]
	}
}
func queries(l int, r int) int {
	//First block
	sum := 0
	for l < r && l%blk_sz != 0 && l != 0 {
		sum += arr[l]
		l++
	}
	// overlap block
	for l+blk_sz-1 <= r {
		sum += block[(l / blk_sz)]
		l += blk_sz
	}
	//last block
	for l <= r {
		sum += arr[l]
		l++
	}
	return sum
}
func main() {
	stdin, err := os.OpenFile("input.txt",
		os.O_RDONLY|os.O_CREATE, 0666)
	if err != nil {
		log.Fatal(err)
	}
	os.Stdin = stdin

	stdout, err := os.OpenFile("output.txt",
		os.O_WRONLY|os.O_CREATE|os.O_TRUNC, 0666)
	if err != nil {
		log.Fatal(err)
	}
	os.Stdout = stdout

	var n, m, r, l int
	fmt.Scanf("%d %d", &n, &m)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i])
	}
	preprocessor(arr, n)

	for m > 0 {
		fmt.Scanf("%d %d", &l, &r)
		ans := queries(l, r)
		fmt.Println(ans)
		m--
	}

}

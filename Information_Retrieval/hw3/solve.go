package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strings"
)

func ifIn(x string, list []string) bool {
	for i := 0; i < len(list); i++ {
		if list[i] == x {
			return true
		}
	}
	return false
}

func round(num float64) int {
	return int(num + math.Copysign(0.5, num))
}

func toFixed(num float64, precision int) float64 {
	output := math.Pow(10, float64(precision))
	return float64(round(num*output)) / output
}

func main() {
	// initialize scanner
	scanner := bufio.NewScanner(os.Stdin)

	// read query number
	var queryNum int
	fmt.Scanln(&queryNum)

	// read data
	var allSystemQuery [][]string
	var allRelevantQuery [][]string
	for i := 0; i < queryNum; i++ {
		var input string
		var temp []string

		if scanner.Scan() {
			input = scanner.Text()
		}
		temp = strings.Fields(input)
		allSystemQuery = append(allSystemQuery, temp)

		if scanner.Scan() {
			input = scanner.Text()
		}
		temp = strings.Fields(input)
		allRelevantQuery = append(allRelevantQuery, temp)
	}

	var score []float64
	for i := 0; i < queryNum; i++ {
		var rightNow float64 = 0
		var scoreNow float64 = 0
		for j := 0; j < len(allSystemQuery[i]); j++ {
			if ifIn(allSystemQuery[i][j], allRelevantQuery[i]) {
				rightNow++
				scoreNow += rightNow / float64(j+1)
			}
		}
		if scoreNow != 0 {
			scoreNow = toFixed(scoreNow/float64(len(allRelevantQuery[i])), 4)
		}
		score = append(score, scoreNow)
	}

	var mapVal float64 = 0
	for i := 0; i < len(score); i++ {
		mapVal += score[i]
	}
	mapVal = mapVal / float64(queryNum)
	fmt.Println(toFixed(mapVal, 4))
}

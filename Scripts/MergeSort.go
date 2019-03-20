package main

import "fmt"

func Merge(arr []int, l, r, m int) {
	
	var n1 int = m - l + 1
	var n2 int =  r - m
	
	L := make([]int, n1)
	R := make([]int, n2)

	for i := 0; i < n1; i++ {
        L[i] = arr[l + i]
    } 
    for j := 0; j < n2; j++{
        R[j] = arr[m + 1+ j]
    } 

	i, j := 0, 0
	var k int = l
	for i<n1 && j<n2 {
		if L[i] <= R[j] {
			arr[k] = L[i]
			i++
		} else {
			arr[k] = R[j]
			j++
		}
		k++
	}

	for i<len(L) {
		arr[k] = L[i]
		i++
		k++
	}

	for j<len(R) {
		arr[k] = R[j]
		j++
		k++
	}

}


func MergeSort(arr []int, l, r int) {
	if l < r {
		var m int = l + (r-l)/2
		MergeSort(arr, l, m)
		MergeSort(arr, m+1, r)

		Merge(arr, l, r, m)
	}
}


func main() {
	arr := []int{12, 11, 13, 5, 6, 7}
	fmt.Printf("Array input: %v\n", arr)
	MergeSort(arr, 0, len(arr)-1)
	fmt.Printf("The sorted array is: %v\n", arr)
}


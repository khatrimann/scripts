package main

import "fmt"

type Node struct {
	data int
	next *Node
}

var HEAD *Node = nil

func insert(data int) {
	var node *Node = new(Node)
	node.data = data
	node.next = nil

	if HEAD == nil {
		HEAD = node
		fmt.Println("Node inserted at head.")
	} else {
		var ptr *Node = HEAD
		
		for ptr.next != nil {
			fmt.Printf("Current node: %d\n", ptr.data)
			ptr = ptr.next
		}
		fmt.Printf("Current node: %d\n", ptr.data)
		ptr.next = node
		fmt.Printf("Inserted node: %d, after current node\n", ptr.next.data)
	}
}

func display() {
	var ptr *Node = HEAD

	for ptr!=nil {
		fmt.Println(ptr.data)
		ptr = ptr.next
	}
}

func main() {
	insert(1)
	insert(2)
	insert(3)
	fmt.Println("The list: ")
	display()
}
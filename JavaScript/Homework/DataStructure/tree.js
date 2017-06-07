class Node {
  constructor(value) {
    this.value = value
    this.parent = null
    this.children = []
  }

  setParent(node) {
    this.parent = node
  }

  setChildren(node) {
    this.children.push(node)
  }
}

//  1
//  |__ 2
//  |   |_ 3
//  |   |_ 4
//  |
//  |__ 5
//  |   |_ 6
//  |
//  |_  7
//  |_  8
//      |_ 9
//         |_ 10

let node1 = new Node(1)
let node2 = new Node(2)
let node3 = new Node(3)
let node4 = new Node(4)
let node5 = new Node(5)
let node6 = new Node(6)
let node7 = new Node(7)
let node8 = new Node(8)
let node9 = new Node(9)
let node10 = new Node(10)

node1.setParent(null)
node1.setChildren(node2)
node1.setChildren(node5)
node1.setChildren(node7)
node1.setChildren(node8)

node2.setParent(node1)
node2.setChildren(node3)
node2.setChildren(node4)

node3.setParent(node2)

node4.setParent(node2)

node5.setParent(node1)
node5.setChildren(node6)

node6.setParent(node5)

node7.setParent(node1)

node8.setParent(node1)
node8.setChildren(node9)

node9.setParent(node8)
node9.setChildren(node10)

node10.setParent(node9)

function traverseTree(root, callback) {
  callback(root)
  root.children.forEach((node) => traverseTree(node, callback))
}

traverseTree(node1, (node) => console.log(node.value))
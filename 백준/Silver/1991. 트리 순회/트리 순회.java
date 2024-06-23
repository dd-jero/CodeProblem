import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Node{
	
	char data;
	Node leftChild;
	Node rightChild;
	
	public Node(char data) {
		this.data = data;
	}

	@Override
	public String toString() {
		return "Node [data=" + data + ", leftChild=" + leftChild + ", rightChild=" + rightChild + "]";
	}
}

class Tree{
	Node root;
	
	public void create(char data, char leftD, char rightD) {
		if(root == null) {
			root = new Node(data);
			root.leftChild = leftD!='.'?new Node(leftD):null;
			root.rightChild = rightD!='.'?new Node(rightD):null;
		}
		else {
			search(root, data, leftD, rightD);
		}
	}
	
	public void search(Node node, char data, char leftD, char rightD) {
		if(node == null) return;
		else if(node.data == data) {
			node.leftChild = leftD!='.'?new Node(leftD):null;
			node.rightChild = rightD!='.'?new Node(rightD):null;
		}else {
			search(node.leftChild, data, leftD, rightD);
			search(node.rightChild, data, leftD, rightD);
		}
	}
	
	public void preOrder(Node node) {
		
		System.out.print(node.data);
		
		if(node.leftChild != null) preOrder(node.leftChild);
		if(node.rightChild != null) preOrder(node.rightChild);
	}
	

	public void inOrder(Node node) {
		
		if(node.leftChild != null) inOrder(node.leftChild);
		
		System.out.print(node.data);
		
		if(node.rightChild != null) inOrder(node.rightChild);
	}
	

	public void postOrder (Node node) {
		
		if(node.leftChild != null) postOrder(node.leftChild);
		if(node.rightChild != null) postOrder(node.rightChild);
		System.out.print(node.data);
	}
}

class Main{
	
	static int N;
	static Tree tree = new Tree();
	static StringBuilder sb;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		sb = new StringBuilder();
		
		N = Integer.parseInt(br.readLine());
		
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			
			char curData = st.nextToken().charAt(0);
			char leftChild = st.nextToken().charAt(0);
			char rightChild = st.nextToken().charAt(0);
			
			tree.create(curData, leftChild, rightChild);
		}
		
		tree.preOrder(tree.root);
		System.out.println();
		tree.inOrder(tree.root);
		System.out.println();
		tree.postOrder(tree.root);
	}
	
	
}
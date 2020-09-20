#include <iostream>

using namespace std;

struct  Node
{
	//자료의 배열
	int* data;

	//노드 포인터 배열
	Node** child;
	//자료 갯수 저장
	int n;
	//부모노드 저장
	Node* parent;
}*root;

class BTree {
public:
	int M;

	bool isOverflow(Node* node) {
		if (node->n >= M)
			return true;
		else
			return false;
	}

	bool isLeafNode(Node* node) {
		for (int i = 0; i < M+1 ; i++)
			if (node->child[i] != NULL)
				return false;
		return true;
	}

	int find_index(Node* node) {
		if (node->parent != NULL) {
			for (int i = 0; i < node->parent->n + 1; i++) {
				if (node->parent->child[i] == node)
					return i;
			}
		}
		return -1;
	}


	void set_parent(Node* node) {
		for (int i = 0; i < node->n + 1; i++)
			if (node->child[i] != NULL)
				node->child[i]->parent = node;
	}



	Node* init() {
		Node* temp = new Node;
		temp->data = new int[M];

		temp->child = new Node * [M+1];
		temp->n = 0;
		temp->parent = NULL;
		for (int i = 0; i < M+1; i++) {
			temp->child[i] = NULL;
		}
		return temp;
	};

	void delet_node(Node* node) {
		free(node);
	}

	void display(Node* node,int level) {
		cout << endl;
		if (node != NULL) {
			int i;
			for (i = 0; i < node->n; i++) {
				display(node->child[i],level+1);
				for (int j = 0; j < level; j++)
					cout << "| \t";
				cout << " " << node->data[i];
			}
			display(node->child[i], level + 1);
		}
	};


	void splitChild(Node* node) {
		int j, mid;
		Node* right = init();
		/*
		node -> 왼쪽으로 가고
		right -> 그 오른쪽으로 가고
		new_parent -> 부모 노드가 됩니다.
		*/
		
		// node의 부모 노드가 없어 새롭게 부모 노드를 만들어주는 경우입니다.
		//(= 루트인경우)
		if (node == root) {
			Node* new_parent = init();
			// M의 중간값을 기준으로 분할합니다.

			mid = node->data[ M/ 2];
			node->data[M / 2] = 0;
			node->n--;
			
			for (j = M / 2 + 1; j < M; j++) {
				// right는 node의 오른쪽 부분 노드를 가져갑니다.
				right->data[j - (M / 2 + 1)] = node->data[j];
				right->child[j - (M / 2 + 1)] = node->child[j];
				right->n++;

				// node는 반 쪼개서 왼쪽 부분 노드만 가지고 갑니다.
				node->data[j] = 0;
				node->n--;
				node->child[j] = NULL;
			}
			right->child[j - (M / 2 + 1)] = node->child[j];
			node->child[j] = NULL;

			new_parent->data[0] = mid;
			new_parent->child[0] = node;
			new_parent->child[1] = right;
			new_parent->n++;
			// 루트 노드로 설정해줍니다.
			//부모노드 설정도
			root = new_parent;
			set_parent(root);
			set_parent(right);
		}
		// 이미 부모 노드가 있는 경우입니다.
		else
		{
			if (node->parent->n >= M) {
				splitChild(node->parent);
			}
			
				int i = find_index(node);
				cout << i << endl;
				mid = node->data[M / 2];
				node->data[M / 2] = 0;
				node->n--;
				for (j = M / 2 + 1; j < M; j++)
				{
					// right은 node의 오른쪽 자식 부분만 가져갑니다.
					right->data[j - (M / 2 + 1)] = node->data[j];
					right->child[j - (M / 2 + 1)] = node->child[j];
					right->n++;

					node->data[j] = 0;
					node->n--;
					node->child[j] = NULL;
				}
				right->child[j - (M / 2 + 1)] = node->child[j];
				node->child[j] = NULL;

				//한칸 씩 뒤로 미룸
				for (int k = node->parent->n; k > i; k--) {
					node->parent->child[k+1] = node->parent->child[k];
					node->parent->data[k] = node->parent->data[k-1];
				}
				
				node->parent->data[i] = mid;
				node->parent->child[i + 1] = right;
				node->parent->n++;
				set_parent(node->parent);
				set_parent(right);
			
			
		}
	}


	void insert(int value) {
		int i=0;
		Node* now = NULL;

		// 만약에 루트 노드가 NULL이라면
		if (root == NULL)
		{
			root = init();
			now = root;
			now->data[0] = value;
			now->n++;
			return;
		}
		// 루트 노드가 NULL이 아니라면
		else
		{
			now = find_node(root, value);
			//  크기가 꽉찼다면
			if (isOverflow(now)) {
				splitChild(now);
				now = find_node(root, value);
				
			}
			// 값을 이동하며 삽입될 자리를 찾습니다.
			for (i = 0; i < now->n; i++)
			{
				if (value < now->data[i]) {
					break;
				}
			}

		}
		//뒤로 한칸 씩 미룸
		for (int k = now->n; k > i; k--) {
			now->data[k] = now->data[k-1];
		}
		now->data[i] = value;
		now->n++;
	};

	Node* find_node(Node* node, int value) {
		if (isLeafNode(node))
			return node;
		else {
			int i;
			for ( i = 0; i < node->n; i++) {
				if ( value < node->data[i] ){
					return find_node(node->child[i], value);
				}
			}
			return find_node(node->child[i], value);
		}

	}

	BTree(int M) {
		root = NULL;
		this->M = M;
	};
};


int main(void)
{
	int i, n, t;
	BTree btree(4);
	cout << "삽입할 원소의 개수를 입력하세요 : ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "원소를 입력하세요 : ";
		cin >> t;
		btree.insert(t);
		cout << "트리를 순회합니다." << endl;
		btree.display(root, 0);
	}

	return 0;
}

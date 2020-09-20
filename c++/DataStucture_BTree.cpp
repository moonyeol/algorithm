#include <iostream>

using namespace std;

struct  Node
{
	//�ڷ��� �迭
	int* data;

	//��� ������ �迭
	Node** child;
	//�ڷ� ���� ����
	int n;
	//�θ��� ����
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
		node -> �������� ����
		right -> �� ���������� ����
		new_parent -> �θ� ��尡 �˴ϴ�.
		*/
		
		// node�� �θ� ��尡 ���� ���Ӱ� �θ� ��带 ������ִ� ����Դϴ�.
		//(= ��Ʈ�ΰ��)
		if (node == root) {
			Node* new_parent = init();
			// M�� �߰����� �������� �����մϴ�.

			mid = node->data[ M/ 2];
			node->data[M / 2] = 0;
			node->n--;
			
			for (j = M / 2 + 1; j < M; j++) {
				// right�� node�� ������ �κ� ��带 �������ϴ�.
				right->data[j - (M / 2 + 1)] = node->data[j];
				right->child[j - (M / 2 + 1)] = node->child[j];
				right->n++;

				// node�� �� �ɰ��� ���� �κ� ��常 ������ ���ϴ�.
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
			// ��Ʈ ���� �������ݴϴ�.
			//�θ��� ������
			root = new_parent;
			set_parent(root);
			set_parent(right);
		}
		// �̹� �θ� ��尡 �ִ� ����Դϴ�.
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
					// right�� node�� ������ �ڽ� �κи� �������ϴ�.
					right->data[j - (M / 2 + 1)] = node->data[j];
					right->child[j - (M / 2 + 1)] = node->child[j];
					right->n++;

					node->data[j] = 0;
					node->n--;
					node->child[j] = NULL;
				}
				right->child[j - (M / 2 + 1)] = node->child[j];
				node->child[j] = NULL;

				//��ĭ �� �ڷ� �̷�
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

		// ���࿡ ��Ʈ ��尡 NULL�̶��
		if (root == NULL)
		{
			root = init();
			now = root;
			now->data[0] = value;
			now->n++;
			return;
		}
		// ��Ʈ ��尡 NULL�� �ƴ϶��
		else
		{
			now = find_node(root, value);
			//  ũ�Ⱑ ��á�ٸ�
			if (isOverflow(now)) {
				splitChild(now);
				now = find_node(root, value);
				
			}
			// ���� �̵��ϸ� ���Ե� �ڸ��� ã���ϴ�.
			for (i = 0; i < now->n; i++)
			{
				if (value < now->data[i]) {
					break;
				}
			}

		}
		//�ڷ� ��ĭ �� �̷�
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
	cout << "������ ������ ������ �Է��ϼ��� : ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "���Ҹ� �Է��ϼ��� : ";
		cin >> t;
		btree.insert(t);
		cout << "Ʈ���� ��ȸ�մϴ�." << endl;
		btree.display(root, 0);
	}

	return 0;
}

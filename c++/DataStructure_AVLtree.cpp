#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
} *root;

class AVLtree {
public :
	//����� ���̸� ����
	int getHeight(Node*);
	//�����μ��� ����
	int getDiff(Node*);
	//RRȸ�� �Լ�
	Node* rotateRR(Node*);
	//LLȸ�� �Լ�
	Node* rotateLL(Node*);
	//LRȸ�� �Լ�
	Node* rotateLR(Node*);
	//RLȸ�� �Լ�
	Node* rotateRL(Node*);
	//Ʈ�� ������ ���ߴ� �Լ�
	Node* balance(Node*);
	//���ο� ��� ���� �Լ�
	Node* insertNode(Node*, int);
	//AVL Ʈ�� ��� �Լ�
	void display(Node*, int);
	//���� ��ȸ
	void inorder(Node*);
	//���� ��ȸ
	void preorder(Node*);
	//���� ��ȸ
	void postorder(Node*);
	//������
	AVLtree() {
		root = NULL;
	};
};

int AVLtree::getHeight(Node* node) {
	int h = 0;
	if (node != NULL) {
		//��ͷ� ���� ������ �˻��ϰ�, �� ���� ���̸� ��
		int left = getHeight(node->left);
		int right = getHeight(node->right);
		int maxHeight = max(left, right);
		h = maxHeight + 1;
	}
	return h;
}

int AVLtree::getDiff(Node* node) {
	//���� �ڽİ� ������ �ڽ��� ������ ���̸� ��ȯ
	int left = getHeight(node->left);
	int right = getHeight(node->right);
	return left - right;
}

Node* AVLtree::rotateRR(Node* node) {
	//������ �ڽ��� ���� �ڽ��� ���� ����� ������ �ڽ�����
	//������ �ڽ��� ���� �ڽ��� ���� ����
	//���������� ������ �ڽ��� ��ȯ������ ������ �ڽ��� ���� ���� ����
	Node* temp;
	temp = node->right;
	node->right = temp->left;
	temp->left = node;
	return temp;
}

Node* AVLtree::rotateLL(Node* node) {
	//RR�� �ݴ� ��������
	Node* temp;
	temp = node->left;
	node->left = temp->right;
	temp->right = node;
	return temp;
}

Node* AVLtree::rotateLR(Node* node) {
	//���� ����� ���� �ڽ��� RR, ������ LL ȸ��
	Node* temp;
	temp = node->left;
	node->left = rotateRR(temp);
	return rotateLL(node);
}

Node* AVLtree::rotateRL(Node* node) {
	//LR�� �ݴ�
	Node* temp;
	temp = node->right;
	node->right = rotateLL(temp);
	return rotateRR(node);
}

Node* AVLtree::balance(Node* node) {
	int factor = getDiff(node);
	//���� ����Ʈ�������� ���ԵǾ� ������ �������
	if (factor > 1) {
		//�� ���� �ڽ��� �����ϋ�
		if (getDiff(node->left) > 0) {
			node = rotateLL(node);
		}
		//�� ������ �ڽ��� �����϶�
		else {
			node = rotateLR(node);
		}
	}
	//������ ���ԵǾ� ������ �������
	else if (factor < -1) {
		if (getDiff(node->right) > 0) {
			node = rotateRL(node);
		}
		else {
			node = rotateRR(node);
		}
	}
	return node;
}

Node* AVLtree::insertNode(Node* root, int value) {
	//Ʈ���� �������
	if (root == NULL) {
		root = new Node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else if (value < root->data) {
		root->left = insertNode(root->left, value);
		root = balance(root);
	}
	//ũ�Ⱑ ������ �����ʿ� ����
	else if (value >= root->data) {
		root->right = insertNode(root->right, value);
		root = balance(root);
	}
	return root;
}

void AVLtree::display(Node* node, int level) {
	//���� Ʈ���� �������������
	if (node != NULL) {
		display(node->right, level + 1);
		cout << endl;
		//��Ʈ���
		if (node == root) {
			cout << "Root ->";
		}
		//���� �������� ���� ��Ʈ�� �ƴҶ�
		for (int i = 0; i < level && node != root; i++) {
			cout << "        ";
		}
		cout << node->data;
		display(node->left, level + 1);
	}
}
void AVLtree::inorder(Node* node) {
	if (node == NULL)
		return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
}

void AVLtree::preorder(Node* node) {
	if (node == NULL)
		return;

	cout << node->data << " ";
	inorder(node->left);
	inorder(node->right);
}
void AVLtree::postorder(Node* node) {
	if (node == NULL)
		return;
	inorder(node->left);
	inorder(node->right);
	cout << node->data << " ";

}

int main(void) {
	int choice, item;
	AVLtree AVL;
	while (1)
	{
		cout << "\n----------------------------" << endl;
		cout << "    C++�� ������ AVL Ʈ��" << endl;
		cout << "----------------------------" << endl;
		cout << "1. ���Ҹ� �����ҷ���." << endl;
		cout << "2. AVL Ʈ���� �����ּ���." << endl;
		cout << "3. ���� ��ȸ�� �ϰ�;��." << endl;
		cout << "4. ���� ��ȸ�� �ϰ�;��." << endl;
		cout << "5. ���� ��ȸ�� �ϰ�;��." << endl;
		cout << "6. ���α׷��� �����ҷ���." << endl;
		cout << "����� ������ �Է��ϼ��� : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������ ������ �Է��ϼ��� : ";
			cin >> item;
			root = AVL.insertNode(root, item);
		case 2:
			if (root == NULL)
			{
				cout << "���� Ʈ���� ������ϴ�." << endl;
				continue;
			}
			cout << "[ AVL Ʈ�� ��� ]" << endl;
			AVL.display(root, 1);
			break;
		case 3:
			cout << "[ ���� ��ȸ ]" << endl;
			AVL.inorder(root);
			cout << endl;
			break;
		case 4:
			cout << "[ ���� ��ȸ ]" << endl;
			AVL.preorder(root);
			cout << endl;
			break;
		case 5:
			cout << "[ ���� ��ȸ ]" << endl;
			AVL.postorder(root);
			cout << endl;
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
	}
	return 0;
}

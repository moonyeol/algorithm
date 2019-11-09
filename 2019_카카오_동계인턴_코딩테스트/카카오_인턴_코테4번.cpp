#include <string>
#include <vector>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	vector<bool> dict(k + 1, true);
	long long temp = room_number[0];
	int j = 0;
	while (true) {
		if (dict[temp]) {
			answer.push_back(temp);
			dict[temp] = false;
			j += 1;
			if (j == room_number.size()) break;
			temp = room_number[j];
		}
		else temp++;
	}
	return answer;
}
//Ž�� �˰����� ��ġ�� ȿ�����׽�Ʈ�� ��������� ������
//�˰��� �������� ���� �Ⱓ�� �ִٺ��� ����� �ȳ��� ��Ǯ����
//������ �°� Ǯ���ߴ�, ȿ�����׽�Ʈ���� ����ó���̴�
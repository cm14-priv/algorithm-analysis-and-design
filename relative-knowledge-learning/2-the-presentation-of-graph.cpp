#include <iostream>
using namespace std;

//ö�����ͣ�ͼ������ DG������ͼ��WDG����Ȩֵ������ͼ��
//UDG: ����ͼ��WUDG: ��Ȩֵ������ͼ
enum GraphKind {DG, WDG, UDG, WUDG};

//vertexType�������ͣ�VRType������֮��Ĺ�ϵ���ͣ�InfoType��������Ϣ����
template <typename VertexType, typename VRType, typename InfoType>
class MGraph {
public:
	MGraph(int vexNum, GraphKind __kind) : vexnum(vexNum), arcnum(0), kind(__kind) {
		vvec = new VertexType[vexnum]; //���䶥����������
		arcs = new ArcCell *[vexnum]; //��̬�����ά���飬 ע���ά����Ķ�̬����
		for (int i = 0; i < vexnum; i++) {
			arcs[i] = new ArcCell[vexnum]; //Ϊÿһ�ж�̬����ռ�
		}
	}

	void Create() {
		switch (kind) {
			case DG:
				CreateDG();    //����һ������ͼ
				break;
			case WDG:
				CreateWDG();    //����һ����Ȩ����ͼ
				break;
			case UDG:
				CreateUDG();    //����һ������ͼ
				break;
			case WUDG:
				CreateWUDG();   //����һ����Ȩ����ͼ
				break;
			default:
				return;
		}
	}

	//��ʼ������������ڽӾ���
	void Init() {
		cout << "������ÿ������Ĺؼ��֣�" << endl;
		VertexType val;
		for (int i = 0; i < vexnum; i++) {
			cin >> val;
			vvec[i] = val;
		}
		for (int i = 0; i < vexnum; i++) {
			ArcCell ac;
			ac.adj = 0;
			ac.info = NULL;
			for (int j = 0; j < vexnum; j++) {
        arcs[i][j] = ac;
			}
		}
	}

	//����һ������ͼ
	void CreateDG() {
		Init();
		int vhead, vtail;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
		while (cin >> vhead >> vtail) {
			arcnum++;
			arcs[vhead][vtail].adj = 1;
		}
	}

	//����һ����Ȩ����ͼ
	void CreateWDG() {
		Init();
		int vhead, vtail;
		InfoType w;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
		while (cin >> vhead >> vtail >> w) {
			arcnum++;
			arcs[vhead][vtail].adj = w;
		}
	}

	//����һ������ͼ
	void CreateUDG() {
		Init();
		int vhead, vtail;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
		while (cin >> vhead >> vtail) {
			arcnum += 2;
			arcs[vhead][vtail].adj  = 1;
			arcs[vtail][vhead].adj  = 1;
		}
	}

	//����һ����Ȩ����ͼ
	void CreateWUDG() {
		Init();
		int vhead, vtail;
		InfoType w;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
		while (cin >> vhead >> vtail >> w) {
			arcnum += 2;
			arcs[vhead][vtail].adj = w;
			arcs[vtail][vhead].adj = w;
		}
	}

	void displayGraph() {
		cout << "�ܹ���" << vexnum << "�����㣬"
			 << arcnum << "����" << endl;
		for (int i = 0; i < vexnum; i++) {
			cout << "��" << i+1 << "�������ǣ�" << vvec[i]
			     << "���ڵı���: ";
		    for (int j = 0; j < vexnum; j++) {
				if (arcs[i][j].adj != 0)
					cout << vvec[j] << "(" << arcs[i][j].adj << ") ";
		    }
			cout << endl;
		}
	}

private:
  struct ArcCell {
		VRType adj;   //�����ϵ���͡�������Ȩͼ����1��0��ʾ;��ʾ������񣻶Դ�Ȩͼ��ΪȨֵ����
		InfoType info;  //�û���ص���Ϣ�ı���
	};
	VertexType *vvec;          	//��������
	ArcCell **arcs;    			//�ڽӾ���
	int vexnum;                 //ͼ�ĵ�ǰ�������
	int arcnum;                 //ͼ�Ļ���
	GraphKind kind;             //ͼ�������־
};

int main() {
	cout << "��������ͼ��" << endl;
	MGraph<char, int, int> udgGraph(8, UDG);
	udgGraph.Create();
	udgGraph.displayGraph();

	cout << "�����Ȩ����ͼ��" << endl;
	MGraph<char, int, int> wudgGraph(9, WUDG);
	wudgGraph.Create();
	wudgGraph.displayGraph();

	cout << "��������ͼ��" << endl;
	MGraph<char, int, int> dgGraph(6, DG);
	udgGraph.Create();
	udgGraph.displayGraph();

	cout << "�����Ȩ����ͼ��" << endl;
	MGraph<char, int, int> wdgGraph(6, WDG);
	wdgGraph.Create();
	wdgGraph.displayGraph();

	system("pause");
	return 0;
}

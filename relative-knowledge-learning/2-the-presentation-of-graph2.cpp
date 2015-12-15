#include <iostream>
using namespace std;

//ö�����ͣ�ͼ������ DG������ͼ��WDG����Ȩֵ������ͼ��
//UDG: ����ͼ��WUDG: ��Ȩֵ������ͼ
enum GraphKind {DG, WDG, UDG, WUDG};

template<typename VertexType, typename InfoType>
class ALGraph {
public:
	ALGraph(int verNum, GraphKind _kind):vexnum(verNum), arcnum(0), kind(_kind) {
		for (int i = 0; i < MAX_VERTEX_NUM; i++)
			vertices[i].firstarc = NULL;
	}

	//����ͼ������ѡ��
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

	//��ӡ�ڽ�����
	void displayGraph() {
		for (int i = 0; i < vexnum; i++) {
			cout << "��" << i+1 << "�������ǣ�" << vertices[i].data << " �ڽӱ�Ϊ: ";
			ArcNode *arcNode = vertices[i].firstarc;

			while (arcNode != NULL) {
				cout << " -> " << vertices[arcNode->adjvex].data << "(" << arcNode->info << ")";
				arcNode = arcNode->nextarc;
			}

			cout << endl;
		}
	}

private:
	//const���ݳ�Ա�����ڹ��캯�����ʼ��
	static const int MAX_VERTEX_NUM = 20;  //��󶥵����
	struct ArcNode {         //����
		int adjvex;        //�û���ָ��Ķ����λ��
		ArcNode *nextarc;  //ָ����һ������ָ��
		InfoType info;     //�û������Ϣ��ָ��
	};

	struct VNode {          //ͷ���
		VertexType data;    //������Ϣ
		ArcNode *firstarc;  //ָ���һ�������ڸö���Ļ���ָ��
	};

	/*VNode AdjList[MAX_VERTEX_NUM];*/
	/* AdjList[MAX_VERTEX_NUM] vertices;*/

	VNode vertices[MAX_VERTEX_NUM];
	int vexnum;             //ͼ�ĵ�ǰ������
	int arcnum;             //ͼ�Ļ���
	GraphKind kind;         //ͼ������

	//��ʼ���ڽ�����ı�ͷ����
	void InitVertics() {
		cout << "������ÿ������Ĺؼ��֣�" << endl;
		VertexType val;
		for (int i = 0; i < vexnum; i++) {
			cin >> val;
			vertices[i].data = val;
		}
	}

	//����һ������
	void insertArc(int vHead, int vTail, InfoType w) {
		//����һ������
		ArcNode *newArcNode = new ArcNode;
		newArcNode->adjvex = vTail;
		newArcNode->nextarc = NULL;
		newArcNode->info = w;

		//arcNode ��vertics[vHead]���ڽӱ�
		ArcNode *arcNode = vertices[vHead].firstarc;
		if (arcNode == NULL) vertices[vHead].firstarc = newArcNode;
		else {
			while (arcNode->nextarc != NULL) {
				arcNode = arcNode->nextarc;
			}
			arcNode->nextarc = newArcNode;
		}
		arcnum++;
	}

	//����һ������ͼ
	void CreateDG() {
		InitVertics();
		int vhead, vtail;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
		while (cin >> vhead >> vtail) {
			insertArc(vhead, vtail, 0);
		}
	}

	//����һ����Ȩ����ͼ
	void CreateWDG() {
		InitVertics();
		int vhead, vtail;
		InfoType w;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
		while (cin >> vhead >> vtail >> w) {
			insertArc(vhead, vtail, w);
		}
	}

	//����һ������ͼ
	void CreateUDG() {
		InitVertics();
		int vhead, vtail;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ������㣺" << endl;
		while (cin >> vhead >> vtail) {
			insertArc(vhead, vtail, 0);
			insertArc(vtail, vhead, 0);
		}
	}

	//����һ����Ȩ����ͼ
	void CreateWUDG() {
		InitVertics();
		int vhead, vtail;
		InfoType w;
		cout << "����������ÿ���ߵĿ�ʼ����ͽ��������Ȩֵ��" << endl;
		while (cin >> vhead >> vtail >> w) {
			insertArc(vhead, vtail, w);
			insertArc(vtail, vhead, w);
		}
	}
};

int main() {
	cout << "����һ��8�����������ͼ:" << endl;
	ALGraph<char, int> udgGraph(8, UDG);
	udgGraph.Create();
	udgGraph.displayGraph();

	cout << "����һ��9������Ĵ�Ȩ����ͼ:" << endl;
	ALGraph<char, int> wudgGraph(9, WUDG);
	wudgGraph.Create();
	wudgGraph.displayGraph();

	cout << "����һ��6�����������ͼ:" << endl;
	ALGraph<char, int> dgGraph(6, DG);
	dgGraph.Create();
	dgGraph.displayGraph();

	cout << "����һ��9������Ĵ�Ȩ����ͼ:" << endl;
	ALGraph<char, int> wdgGraph(9, WDG);
	wdgGraph.Create();
	wdgGraph.displayGraph();

	system("pause");
	return 0;
}

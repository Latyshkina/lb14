#include <afxwin.h> 
// ���������� �������� �������, ��������, ���������� � ������ �������� MFC
int counter = 0;
class CMyMainWnd : public CFrameWnd//����� ������� ���� ����������;������ ���� ����������
{
public: 
	int x; int y; int flag;
	int x1, y1, x2, y2, x3, y3,x4,y4;
	CRect rect; //����� ����� ��������� � ������� ����(�������� ��������� �����)
	CFont* GetFont() const;//�������� ������� ����� ������� ����
	CBrush *ppn=new CBrush;//�����, �������
	CMyMainWnd() //��������� ���� � ����������
		{
		x = 10; y = 10;
			 //constructor
			 Create(NULL,L"My title"); //�����, �������  ����� ���� ��������� �� ������������� ������
			 //���. ���������� � ��� ����� ����, ������� 0
			 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
			 ppn = new CBrush(RGB(255, 0, 0));
		}

		 ~CMyMainWnd()
		 {
			 KillTimer(1);//������� ������, �.�. �� ��������� ������
		 }
		 //���� ���� ���������, ������� ����������� ������ ���������� ClassWizard � AppWizard 
		 afx_msg void OnTimer(UINT); //������������� �������, ������� ����� �������������� ����������
		 afx_msg void OnLButtonDown(UINT, CPoint); //��� ������-�����������
		 afx_msg void OnRButtonDown(UINT, CPoint);
		 afx_msg void OnPaint();
		 afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
			 /*������� OnKeyDown ���������, ���� ��������� ��������� � ������, ��� ������� ������������� ����� �������, 
			 ���������� ��� � ����������� �������� ������ �������.
			 �������� ��������� ����, ����� ���, ������� ������� ������� ���������, ����� ������������ ���������� �������.
			 ���������� ����-���, ��� �������� �������, ���������� ��������� ������� � ����������� ���*/

		 {
			 switch (nChar)
			 {
			 case 49:{ //����
				x1 = 100;
				 y1 = 100;
				 x2 = 10;
				 y2 = 10; flag = 1;
				 ppn = new CBrush(RGB(204, 102, 102)); //����-����
				 // �������, ��� ���������� ������������ 
				 this->Invalidate(); };
				 //�������� � ������������� ��������� ������������ ��������� ����� ����, ��� ����� ���������� ������ ������ ���������
				 break;
			 case 50:{ //������
				x1 = 150;
				 y1 = 150;
				 x2 = 20;
				 y2 = 80; flag = 2;
				 ppn = new CBrush(RGB(255, 255, 0));//������
				 // �������, ��� ���������� ������������ 
				 this->Invalidate(); 
			 }
				 break;
			 case 51:{ //�������������
				x1 = 100;
				 y1 =100;
				 x2 = 400;
				 y2 = 200; flag = 3;
				 ppn = new CBrush(RGB(0, 0, 255)); //�����
				 // �������, ��� ���������� ������������ 
				 this->Invalidate();  }
				 break;
			 case 52:{//�������
								 x1 = 250;
								 y1 = 250;
								 x2 = 60;
								 y2 = 60;  flag = 4;
								 ppn = new CBrush(RGB(255, 140,0 ));//�����-���������
								
								 // �������, ��� ���������� ������������ 
								 this->Invalidate(); }
				 break;
			 case 53:{//������
				 x1 = 250;
				 y1 = 250;
				 x2 = 60;
				 y2 = 60; x3 = 250;
				 y3 = 250;
				 x4 = 60;
				 y4 = 60;
								flag = 5;
								 ppn = new CBrush(RGB(128, 0, 0));//���������-���������
								 // �������, ��� ���������� ������������ 
								 this->Invalidate(); }
				 break;
			 case 54:{//�������

				 x1 = 100;
				 y1 = 100;
				 x2 = 200;
				 y2 = 200;
				 x3 = 300;
				 y3 = 300;
				 x4 = 150;
				 y4 = 150; flag = 6;
								 ppn = new CBrush(RGB(128, 0, 128));//���������
								 
								 // �������, ��� ���������� ������������ 
								 this->Invalidate(); } break;
				
			 }
		 }
		
		 DECLARE_MESSAGE_MAP()//��������� ����� �������� �������� �� ���� ��������
};

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd) //����� ���������(��� ������- ��� ���� �����, ��� �������� ������-��� ������������)

	ON_WM_LBUTTONDOWN() //������������(������)
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	
END_MESSAGE_MAP()

class CMyApp : public CWinApp{//����������� ������ ������ "����������"

public:  CMyApp(){};//�������� ������ ������
		 // constructor
		 virtual BOOL InitInstance()//���������� ��� ������� ����������
		 {   
			 m_pMainWnd=new CMyMainWnd();//�������� ��������� �� ������ ������
			 //����������� ������� ����� ��������� �������� ����(��������� �� ������ �������� ����)
			 m_pMainWnd->ShowWindow(SW_SHOW);//��������� ���� ������������ �� ������
			 return TRUE; //������������ ��� �� �������� ������������� ����������
		 } 
};//���������������� ����������
CMyApp theApp; //�������� ��������� ����������

void CMyMainWnd::OnLButtonDown(UINT, CPoint)
{
	
	 flag = 12;
	ppn = new CBrush(RGB(0, 0, 0));
	// �������, ��� ���������� ������������ 
	this->Invalidate(); 
};

		
	
		

void CMyMainWnd::OnRButtonDown(UINT, CPoint)
{



	SetTimer(1, 3000, NULL);


}

void CMyMainWnd::OnPaint()
{ 
	CPaintDC* pDC = new CPaintDC(this);
	pDC->SelectObject(ppn);
	switch (flag){
	case 1: {pDC->Ellipse(x1, y1, x2, y2); }break;
	case 2: {pDC->Ellipse(x1, y1, x2, y2); }break;
	case 3: {pDC->Rectangle(x1, y1, x2, y2); }break;
	case 4: {pDC->Rectangle(x1, y1, x2, y2); }break;
	case 5: {pDC->Chord(x1, y1, x2, y2, x3, y3, x4, y4); }break;
	case 6: {pDC->Pie(x1, y1, x2, y2, x3, y3, x4, y4); }break;
	case 12: {pDC->Ellipse(0, 0, 0, 0);break;
	} break;
	}
}
void CMyMainWnd::OnTimer(UINT)
{
	
		CClientDC dc(this);
		//CClientDC  -  ��������  �����������,  ���������  �  ����������  �������� ����(client  area).
		dc.TextOutW(x, y, L"            ");
		x=x+5;
		y = y + 5; 
		dc.TextOutW(x, y, L"��� ���� ������");
		counter++;
		if (counter == 5)
		{
			KillTimer(1);
			counter = 0;
		}
}



#include <afxwin.h> 
// содержатся описания классов, структур, переменных и других объектов MFC
int counter = 0;
class CMyMainWnd : public CFrameWnd//задаёт главное окно приложения;создаёт само приложение
{
public: 
	int x; int y; int flag;
	int x1, y1, x2, y2, x3, y3,x4,y4;
	CRect rect; //задаёт новое положение и размеры окна(содержит структуру точку)
	CFont* GetFont() const;//получает текущий шрифт данного окна
	CBrush *ppn=new CBrush;//кисть, заливка
	CMyMainWnd() //создается окно с заголовком
		{
		x = 10; y = 10;
			 //constructor
			 Create(NULL,L"My title"); //метод, который  класс окна наследует от родительского класса
			 //исп. встроенный в мфс класс окна, поэтому 0
			 x1 = 0, y1 = 0, x2 = 0, y2 = 0;
			 ppn = new CBrush(RGB(255, 0, 0));
		}

		 ~CMyMainWnd()
		 {
			 KillTimer(1);//удаляем таймер, т.к. он системный ресурс
		 }
		 //блок кода программы, который управляется только средствами ClassWizard и AppWizard 
		 afx_msg void OnTimer(UINT); //идентефикатор таймера, который будет обрабатываться сообщением
		 afx_msg void OnLButtonDown(UINT, CPoint); //имя метода-обработчика
		 afx_msg void OnRButtonDown(UINT, CPoint);
		 afx_msg void OnPaint();
		 afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
			 /*Событие OnKeyDown наступает, если компонент находится в фокусе, при нажатии пользователем любой клавиши, 
			 Определяет код с виртуальной клавишей данной клавиши.
			 Содержит повторный счет, число раз, сколько нажатие клавиши повторено, когда пользователь удерживает клавишу.
			 Определяет скэн-код, код перехода клавиши, предыдущее состояние клавиши и контекстный код*/

		 {
			 switch (nChar)
			 {
			 case 49:{ //круг
				x1 = 100;
				 y1 = 100;
				 x2 = 10;
				 y2 = 10; flag = 1;
				 ppn = new CBrush(RGB(204, 102, 102)); //фузи-вузи
				 // сообщим, что необходимо перерисовать 
				 this->Invalidate(); };
				 //Сообщает о необходимости полностью перерисовать компонент после того, как будут обработаны другие важные сообщения
				 break;
			 case 50:{ //эллипс
				x1 = 150;
				 y1 = 150;
				 x2 = 20;
				 y2 = 80; flag = 2;
				 ppn = new CBrush(RGB(255, 255, 0));//желтый
				 // сообщим, что необходимо перерисовать 
				 this->Invalidate(); 
			 }
				 break;
			 case 51:{ //прямоугольник
				x1 = 100;
				 y1 =100;
				 x2 = 400;
				 y2 = 200; flag = 3;
				 ppn = new CBrush(RGB(0, 0, 255)); //синий
				 // сообщим, что необходимо перерисовать 
				 this->Invalidate();  }
				 break;
			 case 52:{//квадрат
								 x1 = 250;
								 y1 = 250;
								 x2 = 60;
								 y2 = 60;  flag = 4;
								 ppn = new CBrush(RGB(255, 140,0 ));//темно-оранжевый
								
								 // сообщим, что необходимо перерисовать 
								 this->Invalidate(); }
				 break;
			 case 53:{//сектор
				 x1 = 250;
				 y1 = 250;
				 x2 = 60;
				 y2 = 60; x3 = 250;
				 y3 = 250;
				 x4 = 60;
				 y4 = 60;
								flag = 5;
								 ppn = new CBrush(RGB(128, 0, 0));//коричнево-малиновый
								 // сообщим, что необходимо перерисовать 
								 this->Invalidate(); }
				 break;
			 case 54:{//сегмент

				 x1 = 100;
				 y1 = 100;
				 x2 = 200;
				 y2 = 200;
				 x3 = 300;
				 y3 = 300;
				 x4 = 150;
				 y4 = 150; flag = 6;
								 ppn = new CBrush(RGB(128, 0, 128));//пурпурный
								 
								 // сообщим, что необходимо перерисовать 
								 this->Invalidate(); } break;
				
			 }
		 }
		
		 DECLARE_MESSAGE_MAP()//программа будет обращать внимание на наши действия
};

BEGIN_MESSAGE_MAP(CMyMainWnd, CFrameWnd) //карта сообщений(имя класса- для кого пишем, имя базового класса-кто обрабатывает)

	ON_WM_LBUTTONDOWN() //макрокоманда(макрос)
	ON_WM_RBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	
END_MESSAGE_MAP()

class CMyApp : public CWinApp{//стандартный шаблон класса "приложение"

public:  CMyApp(){};//создаётся объект класса
		 // constructor
		 virtual BOOL InitInstance()//вызывается при запуске приложения
		 {   
			 m_pMainWnd=new CMyMainWnd();//создаётся указатель на объект класса
			 //динамически создаем новый экземпляр главного окна(указатель на объект главного окна)
			 m_pMainWnd->ShowWindow(SW_SHOW);//созданное окно показывается на экране
			 return TRUE; //сигнализация мфс об успешной инициализации приложения
		 } 
};//инициализируется приложение
CMyApp theApp; //создаётся экземпляр приложения

void CMyMainWnd::OnLButtonDown(UINT, CPoint)
{
	
	 flag = 12;
	ppn = new CBrush(RGB(0, 0, 0));
	// сообщим, что необходимо перерисовать 
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
		//CClientDC  -  контекст  отображения,  связанный  с  внутренней  областью окна(client  area).
		dc.TextOutW(x, y, L"            ");
		x=x+5;
		y = y + 5; 
		dc.TextOutW(x, y, L"Тут наша строка");
		counter++;
		if (counter == 5)
		{
			KillTimer(1);
			counter = 0;
		}
}



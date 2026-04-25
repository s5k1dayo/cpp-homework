#include<iostream>
#include<string>
#ifndef ATM
using namespace std;
struct User{
	unsigned long long account; //用户卡号
	char name[10];              //姓名
	char ID[18];                //身份证号
	char password[6];           //密码
	int money;                  //余额
	int lock;                 //锁
	struct User* next;          //指向链表下一个用户的指针
};
User *p,*head,*tail;            //全局变量用户指针用于实现链表
int count=0;                    //全局整型变量用于记录数据库中账号个数
void setchain(){
	p=(struct User*)malloc(sizeof(struct User));
	                           //申请一块内存空间给用户指针p
	head=p;                    //让链表的起始为p
	tail=p;                    //此时链表只有一个指针，末尾也是p
	head->next=NULL;           //p后面没有其他用户指针，next为空
}
User* finduser(unsigned long long x){ //传入要寻找的账号，返回找到的用户地址
	User* answer=head->next;          //定义用户指针等于链表的起始地址
	while(answer!=NULL){              //遍历整个链表，到结尾时answer=NULL
		if(answer->account==x){       //如果找到某个节点的账号值与传入值相同，返回这个节点的地址
			return answer;
		}
		answer=answer->next;          
	}
	return NULL;                      //如果没有找到返回NUll
}
void readuser(){
	FILE* fil=fopen("data.txt","r");                  //打开保存用户数据的文件
	while(!feof(fil)){                                //没读完时一直循环读取
		p=(struct User*)malloc(sizeof(struct User));  //申请一片内存用于承接读到的各项数据
		fscanf(fil,"账号：%llu\n",&p->account);       //读取账号
		fscanf(fil,"姓名：%s\n",&p->name);            //读取姓名
		fscanf(fil,"身份证号：");                     //读取身份证号
		for(int i=0;i<18;i++){
			fscanf(fil,"%c",&p->ID[i]);
		}
		fscanf(fil,"\n");
		fscanf(fil,"密码：");                         //读取密码
		for(int i=0;i<6;i++){
			fscanf(fil,"%c",&p->password[i]);
		}
		fscanf(fil,"\n");
		fscanf(fil,"余额：%d",&p->money);             //读取余额
		fscanf(fil,"\n");
		fscanf(fil,"锁：%d",&p->lock);                //读取是否上锁
		fscanf(fil,"\n_________________________________________\n");
		count++;                                      //数据库中读到的用户个数+1
		tail->next=p;                                 //下面三行用于将读到的数据嵌入链表末尾
		tail=p;
		tail->next=NULL;
	}
	fclose(fil);                                      //关闭文件
	
}
int password(User * x){                   //传入要设置密码的用户地址，返回1或0代表成功或失败
	cout<<"请设置密码："; 
	char pa1[6],pa2[6];                   //定义两个字符串用于承接两次输入的密码
	getchar();                            //吞掉回车
	for(int i=0;i<6;i++){                 //第一次输入
		pa1[i]=getchar();
	}
	getchar();
	cout<<"确认密码：";
	for(int i=0;i<6;i++){                 //第二次输入
		pa2[i]=getchar();
	}
	for(int i=0;i<6;i++){                 //判断两次输入是否一致
		if(pa1[i]!=pa2[i]){
			return 0;                     //不一致返回0
		}
	}
	for(int i=0;i<6;i++){                 //一致直接赋值给用户的密码
		x->password[i]=pa1[i];
	}
	return 1;
}
void signup(){
	system("pause");                              //暂定上一个界面给用户阅读
	system("cls");                                //清除上一个界面
	cout<<"_____________________________"<<endl;  //输出新的界面
	cout<<"|---------注册账户----------|"<<endl;
	p=(struct User*)malloc(sizeof(struct User));  //分配一片空间给即将注册的用户信息
	p->account=1111111111111111111+count;         //按顺序分发卡号
	count++;                                      //新增一个账号
	cout<<"请输入姓名：";                         //注册姓名
	scanf("%s",&p->name);
	system("pause");
	system("cls");
	cout<<"_____________________________"<<endl;
	cout<<"|---------注册账户----------|"<<endl;
	cout<<"请输入身份证号码：";                   //注册身份证号
	getchar();
	for(int i=0;i<18;i++){
		p->ID[i]=getchar();
	}
	system("pause");
	system("cls");
	cout<<"_____________________________"<<endl;
	cout<<"|---------注册账户----------|"<<endl;
	while(!password(p)){                          //调用设置密码函数，如果返回值0失败则一直重复
		cout<<"输入不一致，请重新输入。"<<endl;   //提示语
		system("pause");
		system("cls");
		cout<<"_____________________________"<<endl;
		cout<<"|---------注册账户----------|"<<endl;
	}
	system("pause");
	system("cls");
	cout<<"_____________________________"<<endl;
	cout<<"|---------注册账户----------|"<<endl;
	p->money=10000;                               //初始化用户信息
	p->lock=0;
	tail->next=p;                                 //将新注册的账号加到链表结尾
	tail=p;
	p->next=NULL;
	cout<<"注册成功！"<<endl<<"您的卡号为："<<p->account<<endl;
}                                                 //提示语
int pass(User* x){                          //传入要操作的用户地址，返回0或1表示失败或成功
	cout<<"请输入密码：";
	int u[6];                               //定义数组用于承接输入的密码
	getchar();
	for(int i=0;i<6;i++){                   //输入密码
		u[i]=getchar();
	}
	for(int i=0;i<6;i++){
		if(u[i]!=x->password[i]){           //判断输入的密码和用户密码是否一致
			cout<<"密码错误！"<<endl;
			system("pause");
			system("cls");
			cout<<"_____________________________"<<endl;
			cout<<"|----------登录账户---------|"<<endl;
			return 0;                       //不一致返回0
		}
	}
	cout<<"登录成功。"<<endl;               //一致返回1
	return 1;
}
User* begin(){                                       //返回要登录的用户地址
	cout<<"_____________________________"<<endl;
	cout<<"|-----欢迎使用ATM取款机-----|"<<endl;	
	cout<<"|----------请插卡-----------|"<<endl;
	cout<<"账号：";
	unsigned long long input;                        
	cin>>input;                                       //输入要登陆的账号
	User* login=finduser(input);                      //调用账号查找函数，login用来承接找到的用户地址
	if(login==NULL){                               
		cout<<"账号不存在，请注册！"<<endl;           //没查到则调用注册函数
		signup();
		login=p;                                      //注册的用户地址赋值给login
	}
	else if(login->lock==1){                          //查到的用户被锁则不能登录
		cout<<"账号已锁定，请联系工作人员。"<<endl;
		return NULL;
	}
	system("pause");
	system("cls");
	cout<<"_____________________________"<<endl;
	cout<<"|----------登录账户---------|"<<endl;	
	int wrong=0;                                       //wrong 记录错误次数
	while(!pass(login)){
		if(wrong==2){
			cout<<"密码错误三次，账号已锁定！"<<endl;  //错误三次后锁住当前账号，返回NULL
			login->lock=1;
			return NULL;                               
		}
		wrong++;	
	}	
	return login;                                      //查找成功且没锁返回login
}
void left(User* x){
	system("pause");                                   //暂停上一个界面给用户阅读
	system("cls");                                     //清除上一个界面
	cout<<"_____________________________"<<endl;       //输出新的界面
	cout<<"|取款机V1.0-----------------|"<<endl;
	cout<<"|--------请选择功能---------|"<<endl;
	cout<<"|----1.余额查询-------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"账户余额为："<<x->money<<"元"<<endl;
}
int take(User* x){                                 //传入要操作的用户地址，返回取款金额
	system("pause");
	system("cls");
	cout<<"_____________________________"<<endl;
	cout<<"|取款机V1.0-----------------|"<<endl;
	cout<<"|--------请选择功能---------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|----2.取款-----------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	int how;
	cout<<"请输入取款金额：";
	cin>>how;                                        //输入取款金额
	if(how%100!=0){                                  //如果取款金额不是100倍数则无法取
		cout<<"金额不正确！"<<endl;
		system("pause");
		system("cls");
		cout<<"_____________________________"<<endl;
		cout<<"|取款机V1.0-----------------|"<<endl;
		cout<<"|--------请选择功能---------|"<<endl;
		cout<<"|---------------------------|"<<endl;
		cout<<"|----2.取款-----------------|"<<endl;
		cout<<"|---------------------------|"<<endl;
		cout<<"|---------------------------|"<<endl;
		cout<<"|---------------------------|"<<endl;
		return 0;
	}
	else if(how>x->money){
		cout<<"余额不足！"<<endl;                    //如果取款金额大于余额则无法取
		system("pause");
		system("cls");
		cout<<"_____________________________"<<endl;
		cout<<"|取款机V1.0-----------------|"<<endl;
		cout<<"|--------请选择功能---------|"<<endl;
		cout<<"|---------------------------|"<<endl;
		cout<<"|----2.取款-----------------|"<<endl;
		cout<<"|---------------------------|"<<endl;
		cout<<"|---------------------------|"<<endl;
		cout<<"|---------------------------|"<<endl;
		return 0;
	}
	return how;
}
unsigned long long give(){                          //返回要转账给的卡号或0表示失败
	system("pause");                                //暂停给用户看上一个界面
	system("cls");                                  //清空界面
	cout<<"_____________________________"<<endl;    //输出当前界面
	cout<<"|取款机V1.0-----------------|"<<endl;
	cout<<"|--------请选择功能---------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|----3.转账-----------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	unsigned long long who1,who2;                   //who1和who2用来接前后两次输入的卡号
	cout<<"请输入转给的卡号：";
	cin>>who1;                                      //第一次输入
	cout<<"请再次输入确认：";
	cin>>who2;                                      //第二次输入
	if(who1!=who2){                                 //两次不等则返回0，表示失败
		cout<<"输入不一致！"<<endl;
		return 0;
	}
	if(finduser(who1)==NULL){                       //找不到账号返回0.失败
		cout<<"账户不存在！"<<endl;
		return 0;
	}
	return who1;                                    //没有问题则返回输入的卡号
}
int turn(User* x){                                  //传入要转出的用户地址，返回转账金额或0表示失败
	int how;
	system("pause");
	system("cls");
	cout<<"_____________________________"<<endl;
	cout<<"|取款机V1.0-----------------|"<<endl;
	cout<<"|--------请选择功能---------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|----3.转账-----------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"|---------------------------|"<<endl;
	cout<<"请输入转账金额：";
	cin>>how;                                      //输入转账金额
	if(how>x->money){                              //判断输入金额是否大于余额
		cout<<"余额不足！"<<endl;                  //大于则提示余额不足
		system("pause");
		system("cls");
		cout<<"_____________________________"<<endl;
		cout<<"|取款机V1.0-----------------|"<<endl;
		cout<<"|--------请选择功能---------|"<<endl;
		cout<<"|----1.余额查询-------------|"<<endl;
		cout<<"|----2.取款-----------------|"<<endl;
		cout<<"|----3.转账-----------------|"<<endl;
		cout<<"|----4.修改密码-------------|"<<endl;
		cout<<"|----5.退卡-----------------|"<<endl;
		return 0;                                 //返回0，代表失败
	}
	return how;                                   //没问题则返回转账金额
}
void saveall(){
	FILE* fil=fopen("data.txt","w");                 //打开保存数据的文档
	User* x=head->next;                              //定义用户指针初始值为链表开头
	for(int i=0;i<count;i++){                        //从头开始遍历链表
		fprintf(fil,"账号：%llu\n",x->account);      //重新写入用户信息
		fprintf(fil,"姓名：%s\n",x->name);
		fprintf(fil,"身份证号：");
		for(int i=0;i<18;i++){
			fprintf(fil,"%c",x->ID[i]);
		}
		fprintf(fil,"\n密码：");
		for(int i=0;i<6;i++){
			fprintf(fil,"%c",x->password[i]);
		}
		fprintf(fil,"\n余额：%d",x->money);
		fprintf(fil,"\n锁：%d",x->lock);
		fprintf(fil,"\n_________________________________________\n");
		x=x->next;           
	}
	fclose(fil);                                     //关闭文档
}
void usage(User* x){                                 //传入登陆的用户地址
	system("pause");
	system("cls");
	cout<<"_____________________________"<<endl;
	cout<<"|取款机V1.0-----------------|"<<endl;
	cout<<"|--------请选择功能---------|"<<endl;
	cout<<"|----1.余额查询-------------|"<<endl;
	cout<<"|----2.取款-----------------|"<<endl;
	cout<<"|----3.转账-----------------|"<<endl;
	cout<<"|----4.修改密码-------------|"<<endl;
	cout<<"|----5.退卡-----------------|"<<endl;
	int choice;
	int isRunning=1;                                //代表运行的变量初始值为1
	while(isRunning){                               //变量为1则一直循环
		cin>>choice;                                //输入选择的功能
		int t=0;
		unsigned long long w=0;
		int tu=0;
		User * receive=NULL;
		switch(choice){                             //switch语句实现不同功能的选择
		case 1:                                     //功能1：查询余额
			left(x);                                //调用余额函数，传入登陆的用户地址
			system("pause");
			system("cls");
			cout<<"_____________________________"<<endl;
			cout<<"|取款机V1.0-----------------|"<<endl;
			cout<<"|--------请选择功能---------|"<<endl;
			cout<<"|----1.余额查询-------------|"<<endl;
			cout<<"|----2.取款-----------------|"<<endl;
			cout<<"|----3.转账-----------------|"<<endl;
			cout<<"|----4.修改密码-------------|"<<endl;
			cout<<"|----5.退卡-----------------|"<<endl;
			break;
		case 2:                                     //功能2：取款
			while(!t){
				t=take(x);                          //调用输入金额函数，返回0失败则一直重复
			}
			x->money-=t;                            //修改用户数据，扣钱
			cout<<"出钞成功，请取走现金。"<<endl;
			system("pause");
			system("cls");
			cout<<"_____________________________"<<endl;
			cout<<"|取款机V1.0-----------------|"<<endl;
			cout<<"|--------请选择功能---------|"<<endl;
			cout<<"|----1.余额查询-------------|"<<endl;
			cout<<"|----2.取款-----------------|"<<endl;
			cout<<"|----3.转账-----------------|"<<endl;
			cout<<"|----4.修改密码-------------|"<<endl;
			cout<<"|----5.退卡-----------------|"<<endl;
			break;
		case 3:                                      //功能3：转账
			while(!w){                               //调用输入账户函数，返回0失败则一直重复
				w=give();
			}
			while(!tu){                              //调用转账金额函数，返回0失败则一直重复
				tu=turn(x);
			}
			receive=finduser(w);                     //查找要转账账户的用户地址
			receive->money+=tu;                      //修改数据，加钱
			x->money-=tu;                            //修改数据，扣钱
			cout<<"转账成功。"<<endl;
			system("pause");
			system("cls");
			cout<<"_____________________________"<<endl;
			cout<<"|取款机V1.0-----------------|"<<endl;
			cout<<"|--------请选择功能---------|"<<endl;
			cout<<"|----1.余额查询-------------|"<<endl;
			cout<<"|----2.取款-----------------|"<<endl;
			cout<<"|----3.转账-----------------|"<<endl;
			cout<<"|----4.修改密码-------------|"<<endl;
			cout<<"|----5.退卡-----------------|"<<endl;
			break;
		case 4:                                      //功能4：修改密码
			system("pause");
			system("cls");
			cout<<"_____________________________"<<endl;
			cout<<"|取款机V1.0-----------------|"<<endl;
			cout<<"|--------请选择功能---------|"<<endl;
			cout<<"|---------------------------|"<<endl;
			cout<<"|---------------------------|"<<endl;
			cout<<"|---------------------------|"<<endl;
			cout<<"|----4.修改密码-------------|"<<endl;
			cout<<"|---------------------------|"<<endl;
			while(!password(x)){                     //调用设置密码函数，返回0失败则一直重复
				cout<<"输入不一致，请重新输入。"<<endl;
				system("pause");
				system("cls");
				cout<<"_____________________________"<<endl;
				cout<<"|取款机V1.0-----------------|"<<endl;
				cout<<"|--------请选择功能---------|"<<endl;
				cout<<"|---------------------------|"<<endl;
				cout<<"|---------------------------|"<<endl;
				cout<<"|---------------------------|"<<endl;
				cout<<"|----4.修改密码-------------|"<<endl;
				cout<<"|---------------------------|"<<endl;
			}
			cout<<"修改成功。"<<endl;
			system("pause");
			system("cls");
			cout<<"_____________________________"<<endl;
			cout<<"|取款机V1.0-----------------|"<<endl;
			cout<<"|--------请选择功能---------|"<<endl;
			cout<<"|----1.余额查询-------------|"<<endl;
			cout<<"|----2.取款-----------------|"<<endl;
			cout<<"|----3.转账-----------------|"<<endl;
			cout<<"|----4.修改密码-------------|"<<endl;
			cout<<"|----5.退卡-----------------|"<<endl;
			break;
		case 5:                                      //功能5：退出
			system("pause");
			system("cls");
			cout<<"_____________________________"<<endl;
			cout<<"|----再见-------------------|";
			isRunning=0;                             //表示运行的变量改为0，停止下次循环
			saveall();                               //调用保存函数将所有用户数据从写到文档中
			break;
		default:                                     //输入其他数值提示输入错误
			cout<<"功能不存在，请重新输入！"<<endl;
			system("pause");
			system("cls");
			cout<<"_____________________________"<<endl;
			cout<<"|取款机V1.0-----------------|"<<endl;
			cout<<"|--------请选择功能---------|"<<endl;
			cout<<"|----1.余额查询-------------|"<<endl;
			cout<<"|----2.取款-----------------|"<<endl;
			cout<<"|----3.转账-----------------|"<<endl;
			cout<<"|----4.修改密码-------------|"<<endl;
			cout<<"|----5.退卡-----------------|"<<endl;
			break;
		}
	}
}
#endif

#include <iostream>
#include <string>

using namespace std;

#define فصل    class
#define رقم    int
#define جملة     string
#define جديد     new
#define لكل    for
#define حتى    while
#define فضيني      nullptr
#define مفيش     void
#define امسح     delete
#define عمومي      public
#define رجع    return
#define لو   if
#define غير    else
#define اطبع     cout
#define اتنين      2
#define ستة    6
#define صفر    0
#define مؤشر     *
#define فرقع     pop
#define زق   push
#define كومة     Stack
#define بول    bool
#define آصحيح      isValid
#define علوي     top
#define قائمةمتصلة           LinkedList
#define آمتشابه        isSimilar
#define رآس    head
#define ذيل    tail
#define اساسي      main
#define اقرا     cin
#define امال     hopes
#define حجم    size

	فصل    عقدة     {
	عمومي     :
	رقم     مؤشر     مؤشر     جزيرة      ;
	جملة      تاريخ      ;
	عقدة     مؤشر      بعد    ;
	رقم     ت ;
	عقدة     (){
		جزيرة      = جديد     رقم    مؤشر     [اتنين     ];
		لكل    (رقم     ي  =صفر    ; ي  <اتنين     ; ي  ++){
			جزيرة     [ي  ] = جديد     رقم    [ستة   ];
			لكل    (رقم     ج  =صفر    ; ج  <ستة   ; ج  ++){
				جزيرة     [ي  ][ج  ] = صفر    ;
			}
		}
		تاريخ       = "";
		بعد     = فضيني      ;
		ت  = صفر    ;
	}
	عقدة     (عقدة     مؤشر      غيري     ){
		جزيرة      = جديد     رقم    مؤشر     [اتنين     ];
		لكل    (رقم     ي  =صفر    ; ي  <اتنين     ; ي  ++){
			جزيرة     [ي  ] = جديد     رقم    [ستة   ];
			لكل    (رقم     ج  =صفر    ; ج  <ستة   ; ج  ++){
				جزيرة     [ي  ][ج  ] = غيري     ->جزيرة     [ي  ][ج  ];
			}
		}
		تاريخ       = غيري     ->تاريخ      ;
		بعد     = فضيني      ;
		ت  = غيري     ->ت ;
	}
	مفيش      برينت      (){
		اطبع     << "(" << تاريخ       << ")\n";
		لكل    (رقم     ي  =صفر    ; ي  <اتنين     ; ي  ++){
			لكل    (رقم     ج  =صفر    ; ج  <ستة   ; ج  ++){
				اطبع     << جزيرة     [ي  ][ج  ] << " ";
			}
			اطبع     << "\n";
		}
	}
	~عقدة     (){
		لكل    (رقم     ي  =صفر    ; ي  <اتنين     ; ي  ++){
			امسح     [] جزيرة     [ي  ];
		}
		امسح     [] جزيرة     ;
		بعد     = فضيني      ;
	}
	
};

	فصل    كومة     {
		عمومي      :
	عقدة     مؤشر      علوي    ;
	
	كومة     (){
		علوي     = فضيني      ;
	}
	مفيش      زق   (عقدة     مؤشر      بن   ){
		//عقدة     مؤشر      n = جديد     عقدة     (pn);
		لو   (!علوي    ){
			علوي     = بن   ;
			رجع    ;
		}
		بن   ->بعد     = علوي    ;
		علوي     = بن   ;
	}
	عقدة     مؤشر      فرقع     (){
		لو   (علوي    ){
			عقدة     مؤشر      t = علوي    ;
			علوي     = t->بعد    ;
			t->بعد     = فضيني      ;
			رجع     t;
		}
		رجع     فضيني      ;
	}
};

	بول    آمتشابه        (عقدة     مؤشر      a, عقدة     مؤشر      b){
	لو   (a->ت  == b->ت  ){
		لكل    (رقم     i=0; i<2; i++){
			لكل    (رقم     j=0; j<6; j++){
				لو   (a->جزيرة     [i][j] != b->جزيرة     [i][j])رجع     0;
			}
		}
		رجع     1;
	}
	رجع     0;
}

	فصل    قائمةمتصلة           {
	عمومي      :
	عقدة     مؤشر      رآس    ;
	عقدة     مؤشر      ذيل    ;
	
	قائمةمتصلة           (){
		رآس     = ذيل     = فضيني      ;
	}
	
	مفيش      زق   (عقدة     مؤشر      n){
		لو   (!رآس    ){
			رآس     = n;
			ذيل     = n;
		}غير     {
			ذيل    ->بعد     = n;
			ذيل     = ذيل    ->بعد    ;
		}
	}
	
	رقم     دور    (عقدة     مؤشر      هدف    ){
		رقم     i = 1;
		عقدة     مؤشر      الحالي        = رآس    ;
		حتى    (الحالي       ){
			لو   (آمتشابه        (الحالي       ,هدف    )){
				رجع     i;
			}
			i++;
			الحالي        = الحالي       ->بعد    ;
		}
		رجع     -1;
	}
};

	بول    آصحيح      (عقدة     مؤشر      عقدة     ){
	رقم     s1 = 0;
	رقم     s2 = 0;
	لكل    (رقم     i=0; i<6; i++){
		s1 += عقدة     ->جزيرة     [0][i];
	}
	لكل    (رقم     i=0; i<6; i++){
		s2 += عقدة     ->جزيرة     [1][i];
	}
	لو   (s1>0){
		لكل    (رقم     i=0; i<3; i++){
			لو   (عقدة     ->جزيرة     [0][i]!=0){
				رجع     0;
			}
		}
	}
	لو   (s2>0){
		لكل    (رقم     i=0; i<3; i++){
			لو   (عقدة     ->جزيرة     [1][i]!=0){
				رجع     0;
			}
		}
	}
	رجع     1;
}

	جملة     ترجم     (رقم     i, رقم     j){
	جملة      اسم     [6];
	اسم     [0] = "رجل ١"        ;
	اسم     [1] = "رجل ٢"        ;
	اسم     [2] = "رجل ٣"        ;
	اسم     [3] = "شنطة ١"          ;
	اسم     [4] = "شنطة ٢"          ;
	اسم     [5] = "شنطة ٣"          ;
	لو   (i==j){
		رجع     اسم     [i]+ '*';
	}
	رجع     اسم     [i]+ " مع "        +اسم    [j]+ '*'; 
}

	رقم    Xor(رقم     x){
	لو   (x==1){
		رجع     0;
	}غير     {
		رجع     1;
	}
}

	رقم    اساسي      (){
	عقدة     مؤشر      نهايةالمطاف              = جديد     عقدة     ();
	رقم     آفائز       = 0;
	عقدة     مؤشر      مبدآي       = جديد     عقدة     ();
	اطبع     << "دخل الفلوس اللي في الشنط يا حمادة: \n"                                        ;
	لكل    (رقم     i=0; i<3; i++){
		رقم     x = 0;
		اقرا     >>x;
		مبدآي      ->جزيرة     [0][i] = -x;
		مبدآي      ->جزيرة     [0][i+3] = x;
		نهايةالمطاف             ->جزيرة     [1][i] = -x;
		نهايةالمطاف             ->جزيرة     [1][i+3] = x;
	}
	قائمةمتصلة            مؤشر      مزار      = جديد     قائمةمتصلة           ();
	كومة      مؤشر      امال      = جديد     كومة     ();
	امال     ->زق   (مبدآي      );
	حتى    (امال     ->علوي    ){
		عقدة     مؤشر      الحالي        = امال     ->فرقع     ();
		//الحالي       ->برينت      ();
		مزار     ->زق   (الحالي       );
		لكل    (رقم     i=0; i<3; i++){
			لو   (الحالي       ->جزيرة     [الحالي       ->ت ][i]!=0){
				لكل    (رقم     j=i; j<6; j++){
					عقدة     مؤشر      عيل     = جديد     عقدة     (الحالي       );
					لو   (j==i){
						عيل    ->جزيرة     [Xor(عيل    ->ت )][i] = عيل    ->جزيرة     [عيل    ->ت ][i];
						عيل    ->جزيرة     [عيل    ->ت ][i] = 0;
						جملة      حركة      = ترجم     (i,j);
						عيل    ->تاريخ       += حركة     ;
						عيل    ->ت  = Xor(عيل    ->ت );
					}غير     {
						لو   (الحالي       ->جزيرة     [الحالي       ->ت ][j]!=0){
							عيل    ->جزيرة     [Xor(عيل    ->ت )][i] = عيل    ->جزيرة     [عيل    ->ت ][i];
							عيل    ->جزيرة     [عيل    ->ت ][i] = 0;
							عيل    ->جزيرة     [Xor(عيل    ->ت )][j] = عيل    ->جزيرة     [عيل    ->ت ][j];
							عيل    ->جزيرة     [عيل    ->ت ][j] = 0;
							جملة      حركة      = ترجم     (i,j);
							عيل    ->تاريخ       += حركة     ;
							عيل    ->ت  = Xor(عيل    ->ت );
						}
					}
					لو   (آصحيح      (عيل    )){
						لو   (مزار     ->دور    (عيل    )==-1){
							امال     ->زق   (عيل    );
							لكل    (رقم     i=0 ;i<2; i++){
								لو   (آمتشابه        (عيل    , نهايةالمطاف             )){
									//عيل    ->برينت      ();
									اطبع     << "الخطوات هي: "               ;
									رقم     k = 0;
									اطبع     << "\n" << ++k << "- ";
									لكل    (رقم     a=0; a<عيل    ->تاريخ      .حجم    ()-1; a++){
										لو   (عيل    ->تاريخ      [a] ==  '*'){
											اطبع     << "\n" << ++k << "- ";
										}غير     {
											اطبع     << عيل    ->تاريخ      [a];
										}
									}
									آفائز       = 1;
									اطبع     << "\n***********************\n";
									امال     ->فرقع     ();
								}
								نهايةالمطاف             ->ت   = Xor(نهايةالمطاف             ->ت  );
							}
						}
					}
				}
			}
		}
	}
	لو   (آفائز      ==0){
		اطبع     << "للاسف الفلوس طارت يا صاحبي... متعيطش يا جميل!\n"                                                 ;
	}
	
	رجع     0;
}
class Car:
    zagiganie = 0       
    ezda = 0
    tormoz = 0
    ostanovkaDvig = 0       
    vkluchenieFar = 0
    otkritieZakritieDverei = 0
    def changezagiganie(self, zagiganie):      
        self.zagiganie = zagiganie
    def changeezda(self, ezda):      
        self.ezda = ezda
    def changetormoz(self, tormoz):
        self.tormoz = tormoz
    def changeostanovkaDvig(self, ostanovkaDvig):      
        self.ostanovkaDvig = ostanovkaDvig
    def changevkluchenieFar(self, vkluchenieFar):      
        self.vkluchenieFar = vkluchenieFar
    def changeotkritieZakritieDvere(self, otkritieZakritie):
        self.otkritieZakritieDverei = otkritieZakritie


obj1 = Car()

ans=True

while ans != 0:
      
    print ("""
    0.Выход
    1.Зажигание
    2.Движение
    3.Тормоз
    4.Включение двигателя
    5.Включение фар
    6.Открытие/закрытие дверей    
    """)
    ans = input("Для того чтобы поехать выберите  действие? \n") 

    if ans == "0":
        raise SystemExit
    elif ans=="1":
        if obj1.otkritieZakritieDverei == "1":
            if obj1.zagiganie == 0:
                zajig = input("\n Для того чтобы включить зажигание 1 \n")
                if zajig == "1":
                    print("Вы включили зажигание\n")
                    obj1.changezagiganie(zajig)
          
                if zajig == "0":
                    print("Вы не включили зажигание\n")
            else:
                print("У вас включено зажигание\n")
        else:
            print("Вы либо не сели в машину, либо не закрыли дверь\n")
      
    elif ans=="2":
        if obj1.tormoz  == "1":
            if obj1.ezda == 0:
                start = input("\n Для того чтобы поехать введите 1 \n")
                if start == "1":
                    print("Вы начали движение\n")
                    obj1.changeezda(start)
                    raise SystemExit
                
          
                if start == "0":
                    print("Вы не начали движение\n")
            else:
                print("Вы уже начали движение\n")
        else:
            print("Вы не снялись с ручника\n")  
        
       
    elif ans=="3":
        if obj1.ostanovkaDvig  == "1":
            if obj1.tormoz == 0:
                otklTormoz = input("\n Для того чтобы снять с ручника введите 1 \n")
                if otklTormoz == "1":
                    print("Вы снялись с ручника\n")
                    obj1.changetormoz(otklTormoz)
          
                if otklTormoz == "0":
                    print("Вы не снялись с ручника\n")
            else:
                print("Вы уже снялись с ручника\n")
        else:
            print("Вы не включили двигатель\n")        
       
    elif ans=="4":
        if obj1.vkluchenieFar  == "1":
            if obj1.ostanovkaDvig == 0:
                vklDvig = input("\n Для того чтобы завести двигатель введите 1 \n")
                if vklDvig == "1":
                    print("Вы завели автомобиль\n")
                    obj1.changeostanovkaDvig(vklDvig)
          
                if vklDvig == "0":
                    print("Вы не завели автомобиль\n")
            else:
                print("У вас уже заведён автомобиль\n")
        else:
            print("Вы не включили фары\n")        
       
    elif ans=="5":
        if obj1.zagiganie == "1":
            if  obj1.vkluchenieFar == 0:
                vklFar = input("Для включения фар введите 1\n")
                if vklFar == "1":
                    print("Вы включили фары\n")
                    obj1.changevkluchenieFar(vklFar)
                    
                if vklFar == "0":
                    print("Вы не включили фары\n")
            else:
                print("У вас уже включены фары\n")
        else:
            print("Вы не включили зажигание\n")
        
    elif ans=="6":        
        door = input("Для того чтобы сесть в машину и закрыть дверь введите 1\n")
        if door == "1":
            print("Вы сели в машину и закрыли дверь\n")
            obj1.changeotkritieZakritieDvere(door)
        if door == "0":
            print("Вы не сели в машину и не закрыли дверь\n")
    elif ans !="":
        print("\n Введите правильное значение - действие")
      

    

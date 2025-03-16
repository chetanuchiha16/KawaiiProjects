class Student:
    def __init__(self):
        self.name,self.usn = self.getinfo()
    
    def getinfo(self):
        name = input("Enter the name ")
        usn = input("Enter the usn")
        return name,usn

    
    def display(self):
        print(self.name,self.usn)


student1 = Student()
student1.display()
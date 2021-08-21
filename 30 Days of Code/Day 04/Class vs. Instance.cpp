class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
};

    Person::Person(int initialAge){
      
      //code to run some checks on initialAge
        if(initialAge<0) {cout<<"Age is not valid, setting age to 0."<<endl;age=0;}
        else age = initialAge;

    }

    void Person::amIOld(){
      
      // code to determine if this person's age is old and print the correct statement:
        if(this->age<13) cout<<"You are young."<<endl;
        else if(this->age>=18) cout<<"You are old."<<endl;
        else cout<<"You are a teenager."<<endl;

    }

    void Person::yearPasses(){
      
      // Increment this person's age by 1.
        age++;
    }

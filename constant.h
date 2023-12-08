#ifndef STAR_CLASS
#define STAR_CLASS

#include <iostream>

#define SIZE 100

class star {
private:
    char* clas;
    double estimate_mass;
    double part;
    long int amount;

public:
    star();
    star(const char* c, double e, double p, long int a);
    ~star();
    star(const star& s);
    friend std::ostream& operator<<(std::ostream& stream, const star& o1);
    friend std::istream& operator>>(std::istream& stream, star& o1);
    friend void shapka(void);
    friend void linebuild(void);
    friend void end_of_table(void);
    friend int isvalid(int a, int b);
    star& operator=(const star& s);
    bool operator==(const star& s) const;
    star operator+(const star& s) const;
    void show_row() const;
	void set(const char *c, double e, double p, long int a);
    void get(char *&c, double &e, double &p, long int &a) const;
    void show() const;
};

#endif

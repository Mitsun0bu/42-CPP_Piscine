# include <iostream>
# include <string>

class A
{
	public :

		A(){
			return ;
		};
		A(std::string name) : _hp(10), _ep(10), _ad(0){
			std::cout << "A object created !" << std::endl;
			return ;
		};
		~A(){
			std::cout << "A object " << this->_name << " destroyed." << std::endl;
			return ;
		};

	protected:

	std::string	_name;
	int			_hp;
	int			_ep;
	int			_ad;
};

class B : virtual public A
{
	public :

		B(){
			return ;
		};
		B(std::string name) : A(name){
			std::cout << "B object created !" << std::endl;
			this->_hp = 100;
			this->_ep = 50;
			this->_ad = 20;
			return ;
		};
		~B(){
			std::cout << "B object " << this->_name << " destroyed." << std::endl;
			return ;
		};
};

class C : virtual public A
{
	public :

	C(){
		return ;
	};
	C(std::string name) : A(name){
		std::cout << "C object created !" << std::endl;
		this->_hp = 100;
		this->_ep = 100;
		this->_ad = 30;
		return ;
	};
	~C(){
		std::cout << "C object " << this->_name << " destroyed." << std::endl;
		return ;
	};
};

class D : public B, public C
{
	public :

	D(){
		return ;
	};
	D(std::string name) : A(name + "_comes_from_a"), B(name), C(name){
		this->_name = name;
		std::cout << "D object created !" << std::endl;
		this->_hp = C::_hp;
		this->_ep = B::_ep;
		this->_ad = C::_ad;
		std::cout << "HIT POINTS " << this->_hp << std::endl;
		std::cout << "ENERGY POINTS " << this->_ep << std::endl;
		std::cout << "ATTACK DAMAGE " << this->_ad << std::endl;
		return;
	}
	~D(){
		std::cout << "D object " << this->_name << " destroyed." << std::endl;
		return ;
	};
};

int	main(void)
{
	D	obj_D("TEST");
	return (0);
}
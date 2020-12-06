#include <iostream>
#include <memory> //To use unique_ptr()
#include <utility> //To support move semantic

enum class Insertion_method { push_back, push_front};

template <typename T>
class List {

		//The node is totally related with the class List and totally templated by the class List ==> let's define the class node inside the class List
		//private or public? ==> private, because the user will not need to have direct acces to the node members: value and node next
		struct node {  //The new concept node related with the concept List
			T value;
			std::unique_ptr<node> next; 
			explicit node(const T& v): value{v} {std::cout << "l-value ctor\n"; }; 
			node(const T& v, node* p): next{p}, value{v} {std::cout << "l-value ctor\n";};   

			explicit node(T&& v): value{std::move(v)} {std::cout << "r-value ctor\n"; }; 
			node(T&& v, node* p): next{p}, value{std::move(v)} {std::cout << "r-value ctor\n";};   

			explicit node(const std::unique_ptr<node>& v): value{v->value}{
				std::cout << "l-value copy ctor\n";
				if(v->next)
					next.reset(new node{v->next});

			}
		};


		std::unique_ptr<node> head;
		std::size_t _size;

		//forwarding ref. ==> funct should be templated
		template <typename O>
		void push_front(O&& v){	
			head.reset(new node{std::forward<O>(v), head.release()});			
		};

		template <typename O>
		void push_back(O&& v){

//			auto _node = new node{std::forward<O>(v)};
			auto tmp = head.get();

			if(!tmp){
				head.reset(new node{std::forward<O>(v)});
				return;
			};

			while(tmp->next)
				tmp = tmp->next.get();
			tmp->next.reset(new node{std::forward<O>(v)});
				
		};

		template <typename O>
			void _insert(O&& v, const Insertion_method m);


	public:
		List() = default; //The default generated ctor and desctor are
		~List() = default; //fine, because we do not have row pointers

		//MOVE semantics: we do not have row ptr ==> use the default
		List(List&&) = default; //-->this will move each member of the List, i.e. head and _size
		List& operator=(List&&) = default;

		//COPY semantic
		List(const List& v): _size{v._size} {
			if(v.head)
				head.reset(new node{v.head});
		}

		List& operator=(const List& v){
			head.reset(); //WHYYYYYY?????
			auto tmp = v; //copy ctor
			*this = std::move(tmp); //move assigment to myself
			return *this;
		}

		void insert(const T& v, const Insertion_method m) { _insert(v, m); };
		void insert(T&& v, const Insertion_method m) { _insert(std::move(v), m); };

		friend
		std::ostream& operator<<(std::ostream& os, const List& v){
			auto tmp = v.head.get();
			os << "[" << v._size << "] ";
			while(tmp){
				os << tmp->value << " ";
				tmp = tmp->next.get();
			}
			os << std::endl;
			return os;
		};

};

template <typename T>
template <typename O>
void List<T>::_insert(O&& v, const Insertion_method m){
	std::cout << "forwarding insert" << std::endl;
	switch(m){
		case Insertion_method::push_back:
			push_back(std::forward<O>(v));
			break;
		case Insertion_method::push_front:
			push_front(std::forward<O>(v));
			break;
		default:
			std::cerr << "unknown method" << std::endl;
			break;
	};

	++_size;
}

int main(){

	std::cout << "In this version we are using the forwarding feature\n";
	List<int> l{};

	int a=34;
	double b=43.76;
	float c=8.670;
	char ch='u';

	l.insert(ch, Insertion_method::push_front);
	l.insert(a, Insertion_method::push_back);
	l.insert(3, Insertion_method::push_back);
//	l.insert(2, Insertion_method::push_back);
//	l.insert(5, Insertion_method::push_front);
	l.insert(b, Insertion_method::push_back);
	l.insert(c, Insertion_method::push_back);
	std::cout << l;

	List<int> l2{l};

	std::cout << "insert 99 in l list using the push_front\n";

	l.insert(99, Insertion_method::push_front);

	std::cout << "insert 877 in list l2 (a copy of l) using push_back\n";
	l2.insert(877, Insertion_method::push_back);

	std::cout << "Printing both l and l2\n";

	std::cout << l << "\n" << l2 << std::endl;

//	std::cout << l;

//	l = List<int>{}; //move assigment

//	std::cout << l; //bug: undefined behaviour, we shouldn't use l at right side, because its values were stolen

return 0;
}

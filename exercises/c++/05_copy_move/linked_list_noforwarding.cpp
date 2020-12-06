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
			std::unique_ptr<node> next; //Using a unique_ptr to do the deep copy of the list
			explicit node(const T& v): value{v} {std::cout << "l-value\n"; }; //explicit ==>to avoid implicit conversion from T to node
			node(const T& v, node* p): next{p}, value{v} {std::cout << "l-value\n";}; //Here we pass a row pointer to a constructor of a unique_ptr. If we pass a unique_ptr it will call the copy constructor, but it is delete it the copy ctor for a unique_ptr ==> It is better to pass a row pointer inside the ctor of a unique_ptr  

			explicit node(const std::unique_ptr<node>& v): value{v->value}{
				std::cout << "l-value\n";
				if(v->next)
					next.reset(new node{v->next});

			}
		};


		std::unique_ptr<node> head;
		std::size_t _size;

		void push_front(const T& v){
//			auto tmp = new node{v, head.release()};
//			head.reset(tmp);
			
			head.reset(new node{v, head.release()});
			
		};

		void push_back(const T& v){
			auto tmp = head.get();

			if(!tmp){
				head.reset(new node{v});
				return;
			};

			while(tmp->next)
				tmp = tmp->next.get();
			tmp->next.reset(new node{v});
				
		};


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

		void insert(const T& v, const Insertion_method m);

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
void List<T>::insert(const T& v, const Insertion_method m){
	switch(m){
		case Insertion_method::push_back:
			push_back(v);
			break;
		case Insertion_method::push_front:
			push_front(v);
			break;
		default:
			std::cerr << "unknown method" << std::endl;
			break;
	};

	++_size;
}

int main(){

	std::cout << "In this version we are not using the forwarding feature\n";
	std::cout << "==> the push_back and push_front will be invoqued as l-value\n";
	List<int> l{};

	int a=34;

	l.insert(a, Insertion_method::push_back);
	l.insert(3, Insertion_method::push_back);
	l.insert(2, Insertion_method::push_back);
	l.insert(5, Insertion_method::push_front);
//	l.insert(10, Insertion_method::push_back);
//	l.insert(15, Insertion_method::push_back);
	std::cout << l;

	List<int> l2{l};

	std::cout << "insert 99 in l list using the push_front\n";

	l.insert(99, Insertion_method::push_front);

	std::cout << l;

	std::cout << "insert 877 in list l2 (a copy of l) using push_back\n";
	l2.insert(877, Insertion_method::push_back);
	std::cout << l2;


	l.insert(14, Insertion_method::push_front);

	l2.insert(20, Insertion_method::push_back);
	std::cout << "Printing both l and l2\n";

	std::cout << l << "\n" << l2 << std::endl;



//	l = List<int>{}; //move assigment

//	std::cout << l; //bug: undefined behaviour, we shouldn't use l at right side, because its values were stolen

return 0;
}

/**
 * @file array.h
 * @author Aniket Kumar (geek.aniket.coder@gmail.com)
 * @brief A module which helps in creation of dynamic array.
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#if !defined(ARRAY_H)
#define ARRAY_H
    #include <initializer_list>
    //This is the class which have the features of dynamic array.
    template<typename T>
    class basic_array{
         public:
            T* arr;
            // capacity is the total storage
            int capacity;
            // current is the number of elements
            int current;
         public:
            (basic_array)(){
                arr = new T[1];
                capacity = 1;
                current = 0;
            }
            auto update(int index, T value){
                arr[index] = value;
            }
            auto push(T data){
                // if the number of elements is equal to the
                // capacity, that means we don't have space to
                // accommodate more elements. We need to double the
                // capacity
                if (current == capacity) {
                    T* temp = new T[2 * capacity];
        
                    // copying old array elements to new array
                    for (int i = 0; i < capacity; i++){
                        temp[i] = arr[i];
                    }
        
                    // deleting previous array
                    delete[] arr;
                    capacity *= 2;
                    arr = temp;
                }
                // Inserting data
                arr[current] = data;
                current++;
            }
            auto operator[](int index){
                return this->arr[index];
            }
            auto erase(T e){
                int i;
                for (i=0; i<this->current; i++)
                    if (this->arr[i] == e)
                        break;
                // If element found in array
                if (i < this->current)
                {
                    // reduce size of array and move all
                    // elements on space ahead
                    this->current = this->current - 1;
                    for (int j=i; j<this->current; j++)
                        arr[j] = arr[j+1];
                }
            }
            auto pop(){current--;}
            T* begin() { return &this->arr[0];}
            const T* begin() const { return &this->arr[0];}
            T* end() { return &this->arr[this->current]; }
            const T* end() const { return &this->arr[this->current];}
            // ~basic_array(){delete[] arr;}
    };//basic_array

    /*This class is extended version for basic_array class, this class own many features which can be used to work with dynamic array easily. but note array are not dynamic but as i like the name array i named it array.*/
    template<typename T>
    class array{
         private:
            auto abs(double value){
                double nv = value;
                if(value < 0){
                    nv = nv*(-1);
                }
                return nv;
            }
         public:
            basic_array<T> arr;
         public:
            array(){}
            array(std::initializer_list<T> il){
                for(auto i : il){
                    this->arr.push(i);
                }
            }
            array(const array<T>& arr){
                for(auto i : arr){
                    this->arr.push(i);
                }
            }  
            array(T arr[],int size){
                for(int i=0;i<(size);i++){
                    this->arr.push(arr[i]);
                }
            }
            //Iterators for for each loop.
            T* begin() { return &this->arr.arr[0];}
            const T* begin() const { return &this->arr.arr[0];}
            T* end() { return &this->arr.arr[this->arr.current]; }
            const T* end() const { return &this->arr.arr[this->arr.current];}
            //This method returns the length of the array.
            auto len(){return this->arr.current;}
            //Reading data
            auto operator[](int index){
                T ret;
                if(index<arr.current){
                    ret = arr[index];
                }
                return ret;
            }
            //Adding data
            auto operator+=(T element){arr.push(element);}
            auto operator=(array<T> arr){
                for(int i = 0; i<arr.len();i++){
                   this->arr.push(arr[i]);
                }
            }
            auto operator==(array<T> arr){
                bool state = 1;
                for(int i=0;i<arr.len();i++){
                    if(this->arr[i]!=arr[i]){state = 0;}
                }
                return state;
            }
            auto add(T element){arr.push(element);}
            template<typename... Args>
            auto add(T e1,Args... args){
                arr.push(e1);
                add(args...);
            }
            //Operator for slicing
            auto operator()(int from,int till,int steps=1){
                array<T> n;
                for(int i=from-1;i<till;i+=steps){
                    n.add(this->arr[i]);
                }
                return n;
            }
            auto operator()(int till,int steps=1){
                array<T> n;
                for(int i=0;i<till;i+=steps){
                    n.add(this->arr[i]);
                }
                return n;
            }
            //This method will allocate the memory.
            auto allocate(int size){
                arr.capacity = size;
                arr.current = size;
            }
            //Update data
            auto update(int index,T element){
                arr.update(index,element);
                
            }
            //This method returns the count of the element inside the array.
            auto count(T element){
                int count = 0;
                for(int i = 0; i < this->arr.current; i++){
                    switch (this->arr[i] == element)
                    {
                        case 1:
                            count++;
                        case 0:
                            continue; 
                    }
                }
                return count;
            }
            //This method returns the sum of all elements in the array.
            auto sum(){
                T sum_ = 0;
                for(auto i : this->arr){
                    sum_ += i;
                }
                return sum_;
            }
            //This method returns the product of all elements in the array.
            auto product(){
                T product_ = 1;
                for(auto i : this->arr){
                    product_ = product_ * i;
                }
                return product_;
            }
            //This method returns the mean of all elements in the array.
            auto mean(){
                return this->sum()/this->arr.current;
            }
            //This method sorts the array in ascending order.
            auto sort(){
                for (int j = 0; j < this->arr.current - 1; j++)
                    {
                        // Checking the condition for two
                        // simultaneous elements of the array
                        if (arr[j] > arr[j + 1])
                        {
                            // Swapping the elements.
                            T temp = arr[j];
                            arr.update(j,arr[j + 1]);
                            arr.update(j + 1,temp);
                            
                            // updating the value of j = -1
                            // so after getting updated for j++
                            // in the loop it becomes 0 and
                            // the loop begins from the start.
                            j = -1;
                        }
                    }
            }
            //This method returns the median of all elements in the array
            auto median(){
                this->sort();
                // the autoiable which holds the magnitude of median
                double med;
                /*if number of elements is even then formula
                median = ((n/2)th + (n/2+1)th)/2*/
                if(this->arr.current % 2 == 0){
                    med = (arr[(this->arr.current/2)]+arr[(this->arr.current/2)-1])/2.0;
                }
                //else number of elements is odd so formula n+1/2 th term.
                else{
                    med = arr[((arr.current+1)/2)-1];
                }
                //returning the median.
                return med;
            }

            //This method let you know the maximum value in the array.
            auto max(){
                //assume that the maximum value is at arr[0];
                T max__= this->arr[0];
                //for each loop to work with every element.
                for(auto i : arr){
                    if(i > max__){
                        max__ = i;
                    }
                }
                //returning the maximum value.
                return max__;
            }
            //This method let you know the minimum value in the array.
            auto min(){
                //assume that the minimum value is at arr[0];
                T max__= this->arr[0];
                //for each loop to work with every element.
                for(auto i : arr){
                    if(i < max__){
                        max__ = i;
                    }
                }
                //returning the minimum value.
                return max__;
            }
            //This method let you know the mode magnitude of the array.
            auto mode(){
                array<int> e2;
                //Assigning counts of elements to the new array.
                for(auto i : arr){
                    e2.add(this->count(i));
                }
                T ret;
                for(int i=0;i<e2.len();i++){
                    //Getting at what the element is equal to max count.
                    if(e2[i] == e2.max()){
                        ret = arr[i];
                    }
                }
                return ret;
            }
            //This method pop the elements.
            auto pop(){return this->arr.pop();}
            //This method erase the given element from the array.
            auto erase(T element){
                this->arr.erase(element);
            }

            //This method returns an array of indexes on which the given element is present.
            auto find(T element){
                array<int> index;
                for(int i=0;i<this->len();i++){
                    if(this->arr[i] == element){
                        index.add(i);
                        // break;
                    }
                }
                return index;
            }
            //This method replaces the occurence of element in the array.
            auto replace(T real_element, T new_element){
                for(int i=0;i<this->arr.current;i++){
                    if(this->arr[i] == real_element){
                        this->arr.update(i,new_element);
                    }
                }
            }

            //Typecasting array to int
            //But only works for str to int conversion.
            // auto toint(){
            //     array<int> arr;
            //     for(auto i : this->arr){
            //         arr.add(toint(str(i)));
            //     }
            //     return arr;
            // }
            //But only works for str to double conversion.
            auto todouble(){
                array<double> arr;
                for(auto i : this->arr){
                    arr.add(to_double(i));
                }
                return arr;
            }
            //This method converts numeric array to str array.
            auto tostr(){
                array<str> ret;
                for(auto i : arr){
                    ret.add(to_str(i));
                }
                return ret;
            }

            /*NaN value handling*/

            /**
             * @brief This method returns an array in which all NaN values are replaced.
             * @param substr The substr which will be placed in the array where NaN values are.
             * @param notation This param is made to find how NaN values are represented by autoault it's NaN.
             */
            auto fillna(str subtr,str notation = "NaN"){
                array<T> a;
                for(auto i : arr){
                    a += i;
                }
                for(int i=0;i<a.len();i++){
                    if(a[i] == notation){
                        a.update(i,subtr);
                    }
                }
                return a;
            }
            //This method will return unique values.
            auto unique(){
                int res = 1;
                array<T> e;
                // Pick all elements one by one
                for (int i = 0; i < this->len(); i++) {
                    int j = 0;
                    for (j = 0; j < i; j++)
                        if (arr[i] == arr[j])
                            break;

                    // If not printed earlier, then print it
                    if (i == j)
                        e.add(arr[i]);
                }
                return e;
            };
    };// array

#endif // ARRAY_

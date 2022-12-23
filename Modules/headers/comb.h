#if !defined(COMB_CSQV3_h)
#define COMB_CSQV3_h
    
    #include <stdio.h>
    // #include <string.h>
    //KEYWORDS
    #define starts {
    #define so ){
    #define def auto
    #define var auto
    #define ends }
    #define meth auto
    #define if if( 
    #define ref &
    #define for for(
    #define pub public:
    #define priv private:

    //UTILS:::
    char *strcat(char *s1, const char *s2)
    {
        //Pointer should not null pointer
        if (s1 == NULL) && (s2 == NULL) so
            return NULL;
        ends
        //Create copy of s1
        char *start = s1;
        //Find the end of the destination string
        while(*start != '\0')
        {
            start++;
        }
        //Now append the source string characters
        //until not get null character of s2
        while(*s2 != '\0')
        {
            *start++ = *s2++;
        }
        //Append null character in the last
        *start = '\0';
        return s1;
    };
    int strcmp(const char *X, const char *Y)
    {
        while (*X)
        {
            // if characters differ, or end of the second string is reached
            if *X != *Y so
                break;
            ends
    
            // move to the next pair of characters
            X++;
            Y++;
        }
    
        // return the ASCII difference after converting `char*` to `unsigned char*`
        return *(const unsigned char*)X - *(const unsigned char*)Y;
    }
    int strlen(const char *s)
    {
        int count = 0;
        while(*s!='\0')
        {
            count++;
            s++;
        }
        return count;
    }
    char *strcpy(char *destination, const char *source){
        // if destination is NULL we can't copy to the address, likely something has 
        // startsne wrong perhaps in allocating space for destination, so we just retunr
        // NULL in this case
        if destination == NULL so
            return NULL;
        ends
        
        // use counter variable i to keep track of our index into the destination
        // and source character arrays, start at first index
        int i = 0;

        // copy characters until we encounter the null terminator in the source string
        // which signifies the end of the string
        while (source[i] != '\0')
        {
            // copy the character at index i from the source string to index i in the 
            // destination character array
            destination[i] = source[i];

            // increment i so that the next iteration of the loop looks at and 
            // potentially copies the next character in the source
            i++;
        }
        
        // append a null terminator onto the destination char array to properly 
        // end the string
        destination[i] = '\0';
        
        // return the pointer to the destination string.

        return destination;
    }



    // Class str
    class str{
        // Prototype for '+'
        // operator overloading
        friend str operator+(
        const str& lhs,
        const str& rhs);
        public:
            char* Str;
            // No arguments constructor
            str();
            // pop_back() function
            void pop_bk();

            // push_back() function
            void push_bk(char a);

            // To get the length
            int len();
            //This is used to store the result of concatination.
            auto operator+=(const str& rhs);
            //This is used to get the element at the given index.
            auto operator[](int index){return Str[index];}
            //This will return 1 if given str is equal to this->Str.
            //This will return 1 if given str is equal to this->Str.
            auto operator==(const str& s){
                bool state = 1;
                for int i=0;i<strlen(Str);i++ so
                    if this->Str[i] != s.Str[i] so
                        state = 0;
                        break;
                    ends
                ends
                return state;
            }
            //This will return 1 if given str is equal to this->Str.
            auto operator!=(const str& s){
                bool state = 0;
                for int i=0;i<strlen(Str);i++ so
                    if this->Str[i] != s.Str[i] so
                        state = 1;
                        break;
                    ends
                ends
                return state;
            }
            auto operator!(){
                return str(Str);
            }
            auto operator*(int s);
            // Function to copy the String
            // of length len from position pos
            void copy(char s[], int len, int pos);
            // Swap Strings function
            void swp(str& rhs);

            // ConStructor with 1 arguments
            str(char* val);
            str(const char* val);

            // Copy ConStructor
            str(const str& source);

            // Move ConStructor
            str(str&& source);

            // Overloading the assignment
            // operator
            str& operator=(
                const str& rhs);
            // DeStructor
            ~str() { delete Str; }
    };

    // Overloading the assignment operator
    str& str::operator=(
        const str& rhs)
    {
        if this == &rhs so
            return *this;
        ends
        delete[] Str;
        Str = new char[strlen(rhs.Str) + 1];
        strcpy(Str, rhs.Str);
        return *this;
    }

    // Overloading the plus operator
    str operator+(const str& lhs,
                    const str& rhs)
    {
        int length = strlen(lhs.Str)
                    + strlen(rhs.Str);

        char* buff = new char[length + 1];

        // Copy the Strings to buff[]
        strcpy(buff, lhs.Str);
        strcat(buff, rhs.Str);
        buff[length] = '\0';

        // String temp
        str temp{ buff };

        // delete the buff[]
        delete[] buff;

        // Return the concatenated String
        return temp;
    }
    auto str::operator+=(const str& rhs)
    {
        int length = strlen(this->Str)
                    + strlen(rhs.Str);

        char* buff = new char[length + 1];

        // Copy the Strings to buff[]
        strcpy(buff, this->Str);
        strcat(buff, rhs.Str);
        buff[length] = '\0';

        // String temp
        //str temp{ buff };
        delete Str;
        Str = new char[length+1];
        strcpy(Str,buff);
    }
    auto str::operator*(int s){
        str n;
        for int i=0;i<s;i++ so
            n+=str(this->Str);
        }
        return n;
    }
    // Function to copy the String
    void str::copy(char s[], int len,
                    int pos)
    {
        for int i = 0; i < len; i++ so
            s[i] = Str[pos + i];
        ends
        s[len] = '\0';
    }

    // Function to implement push_bk
    void str::push_bk(char a)
    {
        // Find length of String
        int length = strlen(Str);

        char* buff = new char[length + 2];

        // Copy character from Str
        // to buff[]
        for int i = 0; i < length; i++ so
            buff[i] = Str[i];
        ends
        buff[length] = a;
        buff[length + 1] = '\0';

        // Assign the new String with
        // char a to String Str
        *this = str{ buff };

        // Delete the temp buff[]
        delete[] buff;
    }
    // Function to implement pop_bk
    void str::pop_bk()
    {
        int length = strlen(Str);
        char* buff = new char[length];

        // Copy character from Str
        // to buff[]
        for int i = 0; i < length - 1; i++ so
            buff[i] = Str[i];
        ends
        buff[length-1] = '\0';

        // Assign the new String with
        // char a to String Str
        *this = str{ buff };

        // delete the buff[]
        delete[] buff;
    }

    // Function to implement get_length
    int str::len()
    {
        return strlen(Str);
    }
    
    // Function to illuStrate ConStructor
    // with no arguments
    str::str()
        : Str{ nullptr }
    {
        Str = new char[1];
        Str[0] = '\0';
    }

    // Function to illuStrate ConStructor
    // with one arguments
    str::str(char* val)
    {
        if val == nullptr so
            Str = new char[1];
            Str[0] = '\0';
        ends

        else {

            Str = new char[strlen(val) + 1];

            // Copy character of val[]
            // using strcpy
            strcpy(Str, val);
            Str[strlen(val)] = '\0';
        }
    }
    str::str(const char* ch){
        if ch == nullptr so
            Str = new char[1];
            Str[0] = '\0';
        ends

        else {

            Str = new char[strlen(ch) + 1];

            // Copy character of val[]
            // using strcpy
            strcpy(Str, ch);
            Str[strlen(ch)] = '\0';
        }
    }
    // Function to illuStrate
    // Copy ConStructor
    str::str(const str& source)
    {
        Str = new char[strlen(source.Str) + 1];
        strcpy(Str, source.Str);
    }

    // Function to illuStrate
    // Move ConStructor
    str::str(str&& source)
    {
        Str = source.Str;
        source.Str = nullptr;
    }

    //This function converts int to str.
    auto to_str(int num){
        char* num_ = new char[2500];
        sprintf(num_,"%d",num);
        return str(num_);
    }
    //This function converts double to str.
    auto to_str(double num){
        char* num_ = new char[20];
        sprintf(num_,"%lf",num);
        return str(num_);
    }
    //This function converts double to str.
    auto to_str(long double num){
        char* num_ = new char[2000];
        sprintf(num_,"%Lf",num);
        return str(num_);
    }
    auto to_str(long unsigned int num){
        char* num_ = new char[2000];
        sprintf(num_,"%lu",num);
        return str(num_);
    }
    auto to_str(long int num){
        char* num_ = new char[2000];
        sprintf(num_,"%ld",num);
        return str(num_);
    }
    auto to_str(str s){
        return s;
    }
    auto to_double(int i){
        return double(i);
    }

    int to_int(double d){
        return int(d);
    }
    int to_int(str s) 
    { 
        // Initialize a variable 
        int num = 0; 
        int n = s.len(); 
        // Iterate till length of the string 
        for int i = 0; i < n; i++ so 
            // Subtract 48 from the current digit 
            num = num * 10 + (s[i] - 48); 
        ends
        // Print the answer 
        return num;
    } 

    void showerror(str byclass,str error){
        printf("\033[31mTrackback:\n fatal exception thrown by class <%s> : %s\n\n",byclass.Str,error.Str);
    }  
    namespace exception{
        class IndexBoundError{
            public:
                void getError(){
                    showerror("IndexBoundError","Can't access the index since it doesn't exist.");
                }
        };
        class KeyError{
            public:
                void getError(){
                    showerror("KeyError",str("Key ")+ "is not present in the dictionary.");
                }
        };
        class ValueError{
            public:
                void getError(){
                    showerror("ValueError","bad value passed.");
                }
        };
        class MemoryEstrangementError{
            public:
                void* mem;
                MemoryEstrangementError(void* mem){
                    this->mem = mem;
                }
                void getError(){
                    printf("\033[31mTrackback:\n fatal exception thrown by class <%s> : %s at %p\n\n","MemoryEstrangementError","Couldn't access memory",this->mem);
                }
        };
        class AssertionError{
            public:
                void getError(){
                    showerror("AssertionError","Condition is false");
                }
        };
    }
    def raise(exception::AssertionError err){
        err.getError();
    }
    #define assert(condition) if condition == false so raise(exception::AssertionError()); ends

    
    #include <bits/c++config.h>

    namespace std
    {
    /// initializer_list
    template<class _E>
        class initializer_list
        {
        public:
        typedef _E 		value_type;
        typedef const _E& 	reference;
        typedef const _E& 	const_reference;
        typedef size_t 		size_type;
        typedef const _E* 	iterator;
        typedef const _E* 	const_iterator;

        private:
        iterator			_M_array;
        size_type			_M_len;

        // The compiler can call a private constructor.
        constexpr initializer_list(const_iterator __a, size_type __l)
        : _M_array(__a), _M_len(__l) { }

        public:
        constexpr initializer_list() noexcept
        : _M_array(0), _M_len(0) { }

        // Number of elements.
        constexpr size_type
        size() const noexcept { return _M_len; }

        // First element.
        constexpr const_iterator
        begin() const noexcept { return _M_array; }

        // One past the last element.
        constexpr const_iterator
        end() const noexcept { return begin() + size(); }
        };

    /**
     *  @brief  Return an iterator pointing to the first element of
     *          the initializer_list.
     *  @param  __ils  Initializer list.
     */
    template<class _Tp>
        constexpr const _Tp*
        begin(initializer_list<_Tp> __ils) noexcept
        { return __ils.begin(); }

    /**
     *  @brief  Return an iterator pointing to one past the last element
     *          of the initializer_list.
     *  @param  __ils  Initializer list.
     */
    template<class _Tp>
        constexpr const _Tp*
        end(initializer_list<_Tp> __ils) noexcept
        { return __ils.end(); }
    }
    // #include "str.h"
    // #include "exceptions.h"
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
                if current == capacity so
                    T* temp = new T[2 * capacity];
        
                    // copying old array elements to new array
                    for int i = 0; i < capacity; i++ so
                        temp[i] = arr[i];
                    }
        
                    // deleting previous array
                    delete[] arr;
                    capacity *= 2;
                    arr = temp;
                ends
                // Inserting data
                arr[current] = data;
                current++;
            }
            auto operator[](int index){
                return this->arr[index];
            }
            auto erase(T e){
                int i;
                for i=0; i<this->current; i++ so
                    if this->arr[i] == e so
                        break;
                    ends
                ends
                // If element found in array
                if i < this->current so
                    // reduce size of array and move all
                    // elements on space ahead
                    this->current = this->current - 1;
                    for int j=i; j<this->current; j++ so
                        arr[j] = arr[j+1];
                    ends
                ends
            }
            auto pop(){current--;}
            T* begin() { return &this->arr[0];}
            const T* begin() const { return &this->arr[0];}
            T* end() { return &this->arr[this->current]; }
            const T* end() const { return &this->arr[this->current];}
            // ~basic_array(){delete[] arr;}
    ends;//basic_array



    /*This class is extended version for basic_array class, this class own many features which can be used to work with dynamic array easily. but note array are not dynamic but as i like the name array i named it array.*/
    template<typename T>
    class array{
         private:
            auto abs(double value){
                double nv = value;
                if value < 0 so
                    nv = nv*(-1);
                ends
                return nv;
            }
         public:
            basic_array<T> arr;
         public:
            array(){}
            array(std::initializer_list<T> il){
                for auto i : il so
                    this->arr.push(i);
                ends
            }
            array(const array<T>& arr){
                for auto i : arr so
                    this->arr.push(i);
                ends
            }  
            array(T arr[],int size){
                for int i=0;i<(size);i++ so
                    this->arr.push(arr[i]);
                ends
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
                if index<arr.current so
                    ret = arr[index];
                ends
                else starts
                    exception::IndexBoundError ie;
                    ie.getError();
                ends
                return ret;
            }
            //Adding data
            auto operator+=(T element){arr.push(element);}
            auto operator=(array<T> arr){
                for int i = 0; i<arr.len();i++ so
                   this->arr.push(arr[i]);
                ends
            }
            auto operator==(array<T> arr){
                bool state = 1;
                for int i=0;i<arr.len();i++ so
                    if this->arr[i]!=arr[i] so
                        state = 0;
                    ends
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
                for int i=from-1;i<till;i+=steps so
                    n.add(this->arr[i]);
                ends
                return n;
            }
            auto operator()(int till,int steps=1){
                array<T> n;
                for int i=0;i<till;i+=steps so
                    n.add(this->arr[i]);
                ends
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
                for int i = 0; i < this->arr.current; i++ so
                    switch (this->arr[i] == element)
                    {
                        case 1:
                            count++;
                        case 0:
                            continue; 
                    }
                }
                return count;
            ends
            //This method returns the sum of all elements in the array.
            auto sum(){
                T sum_ = 0;
                for auto i : this->arr so 
                    sum_ += i;
                ends
                return sum_;
            }
            //This method returns the product of all elements in the array.
            auto product(){
                T product_ = 1;
                for auto i : this->arr so
                    product_ = product_ * i;
                ends
                return product_;
            }
            //This method returns the mean of all elements in the array.
            auto mean(){
                return this->sum()/this->arr.current;
            }
            //This method sorts the array in ascending order.
            auto sort(){
                for int j = 0; j < this->arr.current - 1; j++ so
                        // Checking the condition for two
                        // simultaneous elements of the array
                        if arr[j] > arr[j + 1] so
                            // Swapping the elements.
                            T temp = arr[j];
                            arr.update(j,arr[j + 1]);
                            arr.update(j + 1,temp);
                            
                            // updating the value of j = -1
                            // so after getting updated for j++
                            // in the loop it becomes 0 and
                            // the loop begins from the start.
                            j = -1;
                        ends
                    ends
            }
            //This method returns the median of all elements in the array
            auto median(){
                this->sort();
                // the autoiable which holds the magnitude of median
                double med;
                /*if number of elements is even then formula
                median = ((n/2)th + (n/2+1)th)/2*/
                if this->arr.current % 2 == 0){
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
                for auto i : arr so
                    if i > max__ so
                        max__ = i;
                    ends
                ends
                //returning the maximum value.
                return max__;
            }
            //This method let you know the minimum value in the array.
            auto min(){
                //assume that the minimum value is at arr[0];
                T max__= this->arr[0];
                //for each loop to work with every element.
                for auto i : arr){
                    if i < max__){
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
                for auto i : arr so
                    e2.add(this->count(i));
                ends
                T ret;
                for int i=0;i<e2.len();i++ so
                    //Getting at what the element is equal to max count.
                    if e2[i] == e2.max()){
                        ret = arr[i];
                    }
                ends
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
                for int i=0;i<this->len();i++ so
                    if this->arr[i] == element){
                        index.add(i);
                        // break;
                    }
                }
                return index;
            ends
            //This method replaces the occurence of element in the array.
            auto replace(T real_element, T new_element){
                for int i=0;i<this->arr.current;i++ so
                    if this->arr[i] == real_element){
                        this->arr.update(i,new_element);
                    }
                ends
            ends

            array<int> toint(){
                array<int> arr;
                for auto i : this->arr so
                    arr.add(to_int(i));
                ends
                return arr;
            }
            //But only works for str to double conversion.
            auto todouble(){
                array<double> arr;
                for auto i : this->arr so
                    arr.add(to_double(i));
                }
                return arr;
            }
            //This method converts numeric array to str array.
            auto tostr(){
                array<str> ret;
                for auto i : arr so
                    ret.add(to_str(i));
                ends
                return ret;
            ends

            /*NaN value handling*/

            /**
             * @brief This method returns an array in which all NaN values are replaced.
             * @param substr The substr which will be placed in the array where NaN values are.
             * @param notation This param is made to find how NaN values are represented by autoault it's NaN.
             */
            auto fillna(str subtr,str notation = "NaN"){
                array<T> a;
                for auto i : arr so
                    a += i;
                }
                for int i=0;i<a.len();i++ so
                    if a[i] == notation){
                        a.update(i,subtr);
                    }
                }
                return a;
            }
            /**
             * @brief This method returns the count of null values in the array.
             * @param notation The notation to be counted by autoault it is NaN.
             */
            auto isnull(str notation = "NaN"){
                int len = 0;
                for auto i : this->arr so
                    if i == notation){
                        len++;
                    }
                ends
                return len;
            ends
            //This method will return unique values.
            auto unique(){
                int res = 1;
                array<T> e;
                // Pick all elements one by one
                for int i = 0; i < this->len(); i++ so
                    int j = 0;
                    for j = 0; j < i; j++ so
                        if arr[i] == arr[j] so
                            break;
                        ends
                    ends
                    // If not printed earlier, then print it
                    if i == j so
                        e.add(arr[i]);
                    ends
                ends
                return e;
            };
    ends;// array

    //This class stores data in the form of key-value pair same as map.
    template<typename K,typename V>
    class dict{
        public:
            array<K> keys;
            array<V> values;
            //Constructors
            dict(){}
            dict(array<K> keys,array<V> values){
                this->keys = keys;
                this->values = values;
            }
            //This operator reads the value on the basis of key.
            auto operator[](K key){
                V val;
                bool in__ = false;
                for int i=0;i<this->keys.len();i++ so
                    if key == this->keys[i] so
                        val = this->values[i];
                        in__ = true;
                        break;
                    ends
                }
                if in__ == false so
                    exception::KeyError ke;
                    ke.getError();  
                ends
                return val;
            }
            auto operator=(dict<K,V> d){
                this->keys = d.keys;
                this->values = d.values;
            }
            //This method adds the pair.
            auto add(K key,V val){keys.add(key),values.add(val);}
            //This method updates the value.
            auto update(K key,K val){
                bool there = 0;
                for int i=0;i<keys.len();i++ so
                    if key == keys[i] so
                        values.update(i,val);
                        there = 1;
                    ends
                }
                if there == 0 so
                    keys.add(key);
                    values.add(val);
                ends
            ends
            //This method returns a str representation of the dictionary
            auto readall(){
                str s = "{ ";
                for int i=0;i<this->keys.len();i++ so
                    s += to_str(keys[i]) + ":";
                    s += to_str(values[i])+",";
                    s += " ";
                }
                return str(s+"}");
            ends

            auto pop(){
                this->keys.pop();
                this->values.pop();
            }
    ends;
    
    #include "../../base/token.h"

    def raise(exception::KeyError ke) starts;
        ke.getError();
    ends

    def raise(exception::MemoryEstrangementError e) starts;
        e.getError();
    ends

    def raise(exception::IndexBoundError ibe) starts;
        ibe.getError();
    ends

    def raise(exception::ValueError ve) starts;
        ve.getError();
    ends

    def id(void* add) starts;
        return (long int)(add);
    ends

    def range(int start, int lim, int step = 1) starts;
        array<int> res;
        for int i = start; i < lim; i+=step so
            res += i;
        ends
        return res;
    ends

    def range(int lim, int step = 1) starts;
        array<int> res;
        for int i = 0; i < lim; i+=step so
            res += i;
        ends
        return res;
    ends

    def tostr(int num) starts;
        return to_str(num);
    ends

    def tostr(double num) starts;
        return to_str(num);
    ends
    def tostr(long int ptr) starts
        return to_str(ptr);
    ends
    def tostr(str s) starts;
        return to_str(s);
    ends

    def tostr(array<int> arr) starts;
        str s = "[ ";
        for int i : arr so
            s += tostr(i);
            s += ", ";
        ends
        return s+"]";
    ends

    def tostr(array<str> arr) starts;
        str s = "[ ";
        for str i : arr so
            s += "\"";
            s += tostr(i);
            s += "\", ";
        ends
        return s+"]";
    ends

    def tostr(array<double> arr) starts;
        str s = "[ ";
        for double i : arr so
            s += to_str(i);
            s += ", ";
        ends
        return s+"]";
    ends

    def tostr(dict<str,str> d) starts;
        str s;
        for var key : d.keys so
            s += tostr(key) + " : ";
            s += tostr(d[key]) + ", ";
        ends
        return s;
    ends

    def tostr(dict<str,int> d) starts;
        str s;
        for var key : d.keys so
            s += tostr(key) + " : ";
            s += tostr(d[key]) + ", ";
        ends
        return s;
    ends

    def tostr(dict<str,double> d) starts;
        str s;
        for var key : d.keys so
            s += tostr(key) + " : ";
            s += tostr(d[key]) + ", ";
        ends
        return s;
    ends

    def tostr(dict<int,str> d) starts;
        str s;
        for var key : d.keys so
            s += tostr(key) + " : ";
            s += tostr(d[key]) + ", ";
        ends
        return s;
    ends

    def tostr(dict<int,int> d) starts;
        str s;
        for var key : d.keys so
            s += tostr(key) + " : ";
            s += tostr(d[key]) + ", ";
        ends
        return s;
    ends

    def tostr(dict<int,double> d) starts;
        str s;
        for var key : d.keys so
            s += tostr(key) + " : ";
            s += tostr(d[key]) + ", ";
        ends
        return s;
    ends

    def tostr(dict<double,str> d) starts;
        str s;
        for var key : d.keys so
            s += tostr(key) + " : ";
            s += tostr(d[key]) + ", ";
        ends
        return s;
    ends

    def tostr(dict<double,int> d) starts;
        str s;
        for var key : d.keys so
            s += tostr(key) + " : ";
            s += tostr(d[key]) + ", ";
        ends
        return s;
    ends

    def tostr(dict<double,double> d) starts;
        str s;
        for var key : d.keys so
            s += tostr(key) + " : ";
            s += tostr(d[key]) + ", ";
        ends
        return s;
    ends

    def tostr(dict<str,array<str>> d) starts;
        str s;
        for var key : d.keys so
            s += key + " : ";
            s += tostr(d[key]) + ",\n";
        ends;
        return s;
    ends;

    template<typename T> def print(T t) starts
        printf("%s",tostr(t).Str);
    ends
    template<typename T, typename... Args> def print(T t, Args... params) starts
        printf("%s",tostr(t).Str);
        print(params...);
    ends
    template<typename T> def println(T t) starts
        printf("%s\n",tostr(t).Str);
    ends
    template<typename T, typename... Args> def println(T t, Args... params) starts
        printf("%s",tostr(t).Str);
        print(params...);
        printf("\n");
    ends

    def input(str prompt = "") starts;
        printf("%s",prompt.Str);
        char i[900000];
        scanf("%[^\n]s",i);
        return str(i);
    ends
    //////////////////////// Smart Pointers ////////////
    template<typename T>class SmartPtr starts
        public:;
            T* ptr;
            int free_call = 0;
            SmartPtr() starts;
                ;
            ends
            SmartPtr(T* ptr) starts;
                this->ptr = ptr;
            ends
            SmartPtr(T v) starts;
                this->ptr = new T(v);
            ends
            //You could call free method to avoid warning during runtime.
            meth free() starts;
                free_call=1;
                delete this->ptr;
            ends
            meth address(){
                return (long int)(id(this->ptr));
            }
            //This method is used to allocate the memory.
            meth allocate(T val) starts;
                free_call = 0;
                // delete ptr;
                this->ptr = new T(val);
            ends
            ~SmartPtr() starts;
                if free_call == 0 so;
                    // char buffer[10];
                    // char *ptr = new char[20];
                    printf("Memory not is not deallocated so deallocating it at : ");
                    printf("\033[31m%p\033[0m\n",this->ptr);
                    delete ptr; 
                ends
            ends
    ends;
#endif // COMB_CSQV3_h

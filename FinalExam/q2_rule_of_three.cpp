struct Phone{
    double width;
    double height;
    bool isAndroid;
};

class DynamicPhone{
    Phone* data;

public:
    DynamicPhone(Phone d) : data(new Phone(d)){}

    const Phone& operator*() const {return *data;}
    Phone& operator*() {return (*data);}

    DynamicPhone& operator=(const Phone& d){
        *data = d;
        return *this;
    }

    ~DynamicPhone(){
        delete data;
    }
    DynamicPhone(const DynamicPhone& other): data(nullptr){
        Phone* newData = new Phone();
        newData->height = other.data->height;
        newData->width = other.data->width;
        newData->isAndroid = other.data->isAndroid;
        data = newData;

    }
    DynamicPhone& operator=(const DynamicPhone& rhs){
        if(this != &rhs){
            if(data){
                delete data;
                data->height = 0;
                data->width = 0;
                data->isAndroid = false;
            }
            Phone* newData = new Phone();
            newData->height = rhs.data->height;
            newData->width = rhs.data->width;
            newData->isAndroid = rhs.data->isAndroid;
        }
        return *this;
    }
};

int mainInt(void){
    return 1;
}

void mainVoid(void){}

double mainDouble(void){
    return 1.1;
}

double mainDoubleExp(void){
    return 1.100000e+00;
}

double mainDoubleSigned(void){
    return -1.100000e+00;
}
char mainChar(void){
    return 'a';
}
char mainCharTricky(void){
    return '\t';
}
short mainShort(void){
    return 1;
}

int main(void){
    if(1){
        return 1;
    }
    else{
        if(0){
            while(1){
                return 1;
            }
        }
        else{
            return 1;
        }
    }
}
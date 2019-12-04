int hexChar2int(char c)
{
    if(c>='0'&&c<='9') {return c-'0';}
    else if(c>='a'&&c<='f') {return c-'a'+10;}
    else if(c>='A'&&c<='Z') {return c-'A'+10;}
    else{std::cout<<"***** Error,hexChar2int encountered invalid char: "<<c<<" *****\n";}
}


char hexstr2char(std::string input_str)
{
    if(input_str.size()!=2) {std::cout<<"***** Error, hexstr2char encountered invalid input_str: "<<input_str<<" *****\n";exit(0);}
    int ascii_number = hexChar2int(input_str[0])*16 + hexChar2int(input_str[1]);
    return char(ascii_number);
}


std::string encrypt(std::string input_str,std::string key="hongxintouzi")
{
    std::string enc_str;
    char tmp_buf[2];
    sprintf(tmp_buf,"%02d",int(input_str.size()));
    enc_str+=tmp_buf;
    for(auto &c:input_str)
    {
        sprintf(tmp_buf,"%02X",c-'0'+int('0'));
        enc_str += tmp_buf;
    }
    return enc_str;
}

std::string decrypt(std::string sec_str,std::string key="hongxintouzi")
{
    if(sec_str.size()<2) {std::cout<<"***** Error, decrypt encountered error, input sec str size less than 2 *****\n";exit(0);}
    int mingwen_size = hexChar2int(sec_str[0])*16 + hexChar2int(sec_str[1]);
    if(mingwen_size != (sec_str.size()-2)/2) {printf("***** Error, decrypt encountered error: size not match *****\n");fflush(stdout);exit(0);}
    std::string mingwen_str;
    for(int i=2;i<=sec_str.size()-2;i+=2) {mingwen_str += hexstr2char(sec_str.substr(i,2));}
    return mingwen_str;
}


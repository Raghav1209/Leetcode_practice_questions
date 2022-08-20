}else{
char c = ch+1;
s[j] = char(c);
}
}else{
ch = s[j];
if(ch=='a'){
s[j] = 'z';
}else{
char cc = (ch-1);
s[j] = char(cc);
}
}
}
// cout<<s<<" ";
}
return s;
}
};
class Solution {
public:
    string capitalizeTitle(string title) {
        int i=0;
        int n=title.size();
        title+=" ";
        while(i<n){
            if(title[i]==' '){
                i++;
                continue;
            }
            if(i<=n-1 and title[i+1]==' '){
                title[i]=tolower(title[i]);
                i+=2;
            }
            else if(i<=n-2 and title[i+2]==' '){
                title[i]=tolower(title[i]);
                title[i+1]=tolower(title[i+1]);
                i+=3;
            }
            else{
                title[i]=toupper(title[i]);
                i++;
                while(i<=n){
                    if(i==n) break;
                    if(title[i]==' ') {
                        break;
                    }
                    title[i]=tolower(title[i]);
                    i++;
                }
            }  
        }
        title=title.substr(0,n);
        return title;
    }
};
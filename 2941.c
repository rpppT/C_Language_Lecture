#include <stdio.h>

int search(char * p_buf){
	int i = 0;
	int n_alp = 0;

	while(p_buf[i] != 0){
	   if(p_buf[i+1] != 0){
		  switch(p_buf[i]){
			case 'c':
		      if(p_buf[i+1] == '=' || p_buf[i+1] == '-'){
		     	i = i + 1;
				n_alp++;	    		   	
		      }else{
		      	n_alp++;
			  }break; 
		     case 'd':
		     	if(p_buf[i+1] == 'z' && p_buf[i+2] == '='){
		     		i = i + 2;
		     		n_alp++;
				}else if(p_buf[i+1] == '-'){
					i = i + 1;
					n_alp++;
				}else{
				    n_alp++;
				}break;
			 case 'l':
			 	if(p_buf[i+1] == 'j'){
			 		i = i + 1;
			 		n_alp++;
				 }else{
				     n_alp++;
				 }break;
			  case 'n':
			  	if(p_buf[i+1] == 'j'){
			  		i = i + 1;
			  		n_alp++;	
				  }else{
				  	n_alp++;
				  }break;
			  case 's':
			  	if(p_buf[i+1] == '='){
		     	  i = i + 1;
			      n_alp++;	    		     	
		      	  }else{
		      	  	n_alp++;
				}break; 
		      case 'z':
			    if(p_buf[i+1] == '='){
		     	  i = i + 1;
				   n_alp++;	   		     	
		      }else{
		      	n_alp++;
			  }break; 
			    default:
			    n_alp++; 
		   }
	  }
	  i++; 
	}
	return n_alp;
}

int main(){
	char buf[100] = {0,};

	fgets(buf, 100, stdin);

	printf("%d\n", search(buf));	
}

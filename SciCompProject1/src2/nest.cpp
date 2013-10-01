/*nest.cpp
	Tyler Jackson
*/

double nest(Mat& a, double x);

inline double nest(Mat&a, double x){
                int n=a.Rows();
                double p=a(n-1);
                for(int i=n-2;i>=0;i--){
                        p=a(i)+p*x;
                }
                return p;
        }



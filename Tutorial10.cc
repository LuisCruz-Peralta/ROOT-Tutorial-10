void Tutorial10(){

   TCanvas *c1 = new TCanvas();
   
   TGraphErrors *gr = new TGraphErrors();
   
   fstream file;
   file.open("data3.txt",ios::in);

   double x,y,ex,ey;
   
   int n=0;
   
   while(1){
     file>>x>>y>>ex>>ey; //Valor de cada entrada del .txt
     
     n = gr->GetN(); //Obtener el numero de datos del documento .txt
     
     gr->SetPoint(n,x,y);
     gr->SetPointError(n,ex,ey);
     
     if(file.eof()) break;
   }

   gr->Draw("A*");

   TF1 *fit = new TF1("fit","pol1",0,5); //Ajuste lineal
   gr->Fit("fit");
}

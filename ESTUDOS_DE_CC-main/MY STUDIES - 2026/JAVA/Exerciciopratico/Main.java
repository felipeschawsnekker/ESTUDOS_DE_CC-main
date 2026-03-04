import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner entrada= new Scanner(System.in);
        Carro c1 = new Carro();
        
        System.out.println("Modelo: ");
        c1.modelo=entrada.nextLine();
        
        System.out.println("Cor: ");
        c1.cor=entrada.nextLine();
        
        System.out.println("Placa: ");
        c1.placa=entrada.nextLine();
        
        System.out.println("Ano: ");
        c1.ano=entrada.nextInt();
        
        c1.Estacionar_Carro();
        
        System.out.println("Horas estacionado: ");
        double horas=entrada.nextDouble();
        
        c1.Sair_Carro(horas);
        
        entrada.close();
    }
}

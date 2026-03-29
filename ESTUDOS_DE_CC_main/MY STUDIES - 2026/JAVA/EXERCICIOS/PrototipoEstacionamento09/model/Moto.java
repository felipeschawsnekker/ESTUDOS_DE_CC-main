package ESTUDOS_DE_CC_main.MY_STUDIES_2026.JAVA.EXERCICIOS.PrototipoEstacionamento09.model;
public class Moto extends Veiculo{

    public Moto(String modelo, String placa){
        super(modelo,placa);
    }
    @Override
    public int getValorPorHora(){
        if(getFidelizado()==true){
            System.out.println("Veiculo fidelizado!");
        return 2;
        }
        else{
            return 3;
        }
    }
}

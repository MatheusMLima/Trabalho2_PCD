import java.util.concurrent.Semaphore;

public class TrafficController {

    private Semaphore sem = new Semaphore(1, true); //cria uma lista de espera FIFO com apenas 1 permissão, um de cada vez

    public void enterLeft() {
        try {
            sem.acquire(); // vai adquirir a permissão de cruzar a ponte
        } catch (InterruptedException e) {
            System.out.println("Excecao");
        }
    }
    public void enterRight() {
        try {
            sem.acquire();
        } catch (InterruptedException e) {
            System.out.println("Excecao");
        }
    }
    public void leaveLeft() {
        sem.release(); //libera a permissão para que ela possa ser pega pelo proximo carro
    }
    public void leaveRight() {
        sem.release();
    }

}
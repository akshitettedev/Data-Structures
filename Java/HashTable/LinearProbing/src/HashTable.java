/** Integer set using open addressing and linear probing. */
public class HashTable {
    private static final byte EMPTY=0, OCCUPIED=1, DELETED=2;
    private final int[] keys; private final byte[] state; private int size;
    public HashTable(int capacity){if(capacity<=0)throw new IllegalArgumentException();keys=new int[capacity];state=new byte[capacity];}
    private int hash(int key){return Math.floorMod(key,keys.length);}
    public int size(){return size;}
    public boolean insert(int key){int firstDeleted=-1;int start=hash(key);for(int i=0;i<keys.length;i++){int j=(start+i)%keys.length;if(state[j]==OCCUPIED&&keys[j]==key)return false;if(state[j]==DELETED&&firstDeleted<0)firstDeleted=j;if(state[j]==EMPTY){int at=firstDeleted>=0?firstDeleted:j;keys[at]=key;state[at]=OCCUPIED;size++;return true;}}if(firstDeleted>=0){keys[firstDeleted]=key;state[firstDeleted]=OCCUPIED;size++;return true;}throw new IllegalStateException("Hash table is full");}
    public boolean search(int key){int start=hash(key);for(int i=0;i<keys.length;i++){int j=(start+i)%keys.length;if(state[j]==EMPTY)return false;if(state[j]==OCCUPIED&&keys[j]==key)return true;}return false;}
    public boolean delete(int key){int start=hash(key);for(int i=0;i<keys.length;i++){int j=(start+i)%keys.length;if(state[j]==EMPTY)return false;if(state[j]==OCCUPIED&&keys[j]==key){state[j]=DELETED;size--;return true;}}return false;}
    public void display(){for(int i=0;i<keys.length;i++)System.out.println(i+": "+(state[i]==OCCUPIED?keys[i]:state[i]==DELETED?"<deleted>":"<empty>"));}
}

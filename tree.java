import java.util.LinkedList;
import java.util.Queue;
import java.lang.Math;
class tree{
	int val;
	tree left;
	tree right ;
// Method performLevelOrderTravsersal uses Queue for maintaining the order
	public  static tree performLevelOrderTravsersal(tree root){
		Queue<tree> q = new LinkedList<>();
		q.add(root);
		tree t = null;

		while(q.peek()!= null)
		{
			t = q.poll();
			System.out.println("traversal" + t.val);
			if(t.left!= null){

				q.add(t.left);
				 if(t.right==null)
				 {
				 	break;
				 }

			}
			else
			{
				break;
			}
			
			

			if(t.right!=null){

				q.add(t.right);

			

		}



		}

		return t;


	}
	public static void preorderTraversal(tree root)
	{
		tree ptr = root;
		if (ptr != null)
		{
			System.out.println(ptr.val);
             preorderTraversal(ptr.left);
             preorderTraversal(ptr.right);

		}
	}

    public  static  tree insertNode(int data, tree root)
    {
        tree t = new tree();
        t.val =  data;
        t.left = null;
        t.right = null;

        if(root==null)
        {   //System.out.println(data); 
        	root = t;
        	//System.out.println(t.val);
        }
        else
        {
        	tree loc = performLevelOrderTravsersal(root);
        	if(loc.left ==null)
        	{
        		loc.left = t;
        	}
        	else
        		loc.right = t;

        	//System.out.println(loc.left.val);
        }

        return root;
    }

    public static int maxi(tree root)
    {   int maxii = Integer.MIN_VALUE;  
     if(root!=null)
    	{    int root_val = root.val;
    		int left = maxi(root.left);
            System.out.println(left);
    		int right = maxi(root.right);
    		System.out.println(right);
    		if(left>right)
    			maxii = left;
    		else 
    			maxii =  right;	
    		if(root_val>maxii)
    			maxii= root_val;
    	}

    	return maxii;
    }

    public static int mini(tree root)
    {   int minii = Integer.MAX_VALUE;  
     if(root!=null)
    	{    int root_val = root.val;
    		int left = mini(root.left);
            //System.out.println(left);
    		int right = mini(root.right);
    		//System.out.println(right);
    		if(left<right)
    			minii = left;
    		else 
    			minii = right;	
    		if(root_val<minii)
    			minii= root_val;
    	}

    	return minii;
    }


	public static void main(String[] args)
	{       tree root = null;
		    tree lastNode = null;
		   System.out.println("mainblock---------------------");
          root = insertNode(2 , root);

           root = insertNode(3 , root);
           root = insertNode(4,root);
           System.out.println(root.left.val);
           System.out.println(root.right.val);

           root = insertNode(5,root);
           root = insertNode(8,root);

          
           preorderTraversal(root);
           System.out.println("I am maximun" + maxi(root));
           System.out.println("I am minimum" + mini(root));
	}
}
// HASH COLLISIONS: YES
// timestamp: 1.638268271326E12

package ex10;

import com.area9innovation.flow.*;

public class Struct_RatFunc extends Struct {
	public Struct_Polinome f_num;
	public Struct_Polinome f_denum;

	public Struct_RatFunc() {}
	public Struct_RatFunc(Struct_Polinome a_num, Struct_Polinome a_denum) {
		f_num = a_num;
		f_denum = a_denum;
	}

	public int getTypeId() { return 101; }
	public String getTypeName() { return "RatFunc"; }

	private static final String[] field_names = new String[] {
		"num", "denum"
	};
	private static final RuntimeType[] field_types = new RuntimeType[] {
		RuntimeType.STRUCT, RuntimeType.STRUCT
	};
	public String[] getFieldNames() { return field_names; }
	public RuntimeType[] getFieldTypes() { return field_types; }

	public Object[] getFields() {
		return new Object[] {
			f_num, f_denum
		};
	}
	@SuppressWarnings("unchecked")
	public void setFields(Object[] values) {
		if (values.length != 2)
			throw new IndexOutOfBoundsException("Invalid field count in RatFunc");
		f_num = (Struct_Polinome)values[0];
		f_denum = (Struct_Polinome)values[1];
	}

	public int compareTo(Struct other_gen) {
		if (other_gen == this) return 0;
		int tmp = other_gen.getTypeId();
		if (tmp != 101) return 101-tmp;
		Struct_RatFunc other = (Struct_RatFunc)other_gen;
		tmp = f_num.compareTo(other.f_num);
		if (tmp != 0) return tmp;
		tmp = f_denum.compareTo(other.f_denum);
		return tmp;
	}
}

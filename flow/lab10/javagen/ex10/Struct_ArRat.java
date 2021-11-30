// HASH COLLISIONS: YES
// timestamp: 1.63826827128E12

package ex10;

import com.area9innovation.flow.*;

public class Struct_ArRat extends Struct {
	public int f_num;
	public int f_denum;

	public Struct_ArRat() {}
	public Struct_ArRat(int a_num, int a_denum) {
		f_num = a_num;
		f_denum = a_denum;
	}

	public int getTypeId() { return 12; }
	public String getTypeName() { return "ArRat"; }

	private static final String[] field_names = new String[] {
		"num", "denum"
	};
	private static final RuntimeType[] field_types = new RuntimeType[] {
		RuntimeType.INT, RuntimeType.INT
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
			throw new IndexOutOfBoundsException("Invalid field count in ArRat");
		f_num = (Integer)values[0];
		f_denum = (Integer)values[1];
	}

	public int compareTo(Struct other_gen) {
		if (other_gen == this) return 0;
		int tmp = other_gen.getTypeId();
		if (tmp != 12) return 12-tmp;
		Struct_ArRat other = (Struct_ArRat)other_gen;
		if (f_num != other.f_num)
			return (f_num > other.f_num) ? 1 : -1;
		if (f_denum != other.f_denum)
			return (f_denum > other.f_denum) ? 1 : -1;
		return 0;
	}
}

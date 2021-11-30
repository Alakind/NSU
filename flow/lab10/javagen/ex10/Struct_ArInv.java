// HASH COLLISIONS: YES
// timestamp: 1.638268271278E12

package ex10;

import com.area9innovation.flow.*;

public class Struct_ArInv extends Struct {
	public Struct f_arg;

	public Struct_ArInv() {}
	public Struct_ArInv(Struct a_arg) {
		f_arg = a_arg;
	}

	public int getTypeId() { return 10; }
	public String getTypeName() { return "ArInv"; }

	private static final String[] field_names = new String[] {
		"arg"
	};
	private static final RuntimeType[] field_types = new RuntimeType[] {
		RuntimeType.STRUCT
	};
	public String[] getFieldNames() { return field_names; }
	public RuntimeType[] getFieldTypes() { return field_types; }

	public Object[] getFields() {
		return new Object[] {
			f_arg
		};
	}
	@SuppressWarnings("unchecked")
	public void setFields(Object[] values) {
		if (values.length != 1)
			throw new IndexOutOfBoundsException("Invalid field count in ArInv");
		f_arg = (Struct)values[0];
	}

	public int compareTo(Struct other_gen) {
		if (other_gen == this) return 0;
		int tmp = other_gen.getTypeId();
		if (tmp != 10) return 10-tmp;
		Struct_ArInv other = (Struct_ArInv)other_gen;
		tmp = f_arg.compareTo(other.f_arg);
		return tmp;
	}
}

// HASH COLLISIONS: YES
// timestamp: 1.636517114358E12

package ex7;

import com.area9innovation.flow.*;

public class Struct_ArDiv extends Struct {
	public Struct f_lhs;
	public Struct f_rhs;

	public Struct_ArDiv() {}
	public Struct_ArDiv(Struct a_lhs, Struct a_rhs) {
		f_lhs = a_lhs;
		f_rhs = a_rhs;
	}

	public int getTypeId() { return 8; }
	public String getTypeName() { return "ArDiv"; }

	private static final String[] field_names = new String[] {
		"lhs", "rhs"
	};
	private static final RuntimeType[] field_types = new RuntimeType[] {
		RuntimeType.STRUCT, RuntimeType.STRUCT
	};
	public String[] getFieldNames() { return field_names; }
	public RuntimeType[] getFieldTypes() { return field_types; }

	public Object[] getFields() {
		return new Object[] {
			f_lhs, f_rhs
		};
	}
	@SuppressWarnings("unchecked")
	public void setFields(Object[] values) {
		if (values.length != 2)
			throw new IndexOutOfBoundsException("Invalid field count in ArDiv");
		f_lhs = (Struct)values[0];
		f_rhs = (Struct)values[1];
	}

	public int compareTo(Struct other_gen) {
		if (other_gen == this) return 0;
		int tmp = other_gen.getTypeId();
		if (tmp != 8) return 8-tmp;
		Struct_ArDiv other = (Struct_ArDiv)other_gen;
		tmp = f_lhs.compareTo(other.f_lhs);
		if (tmp != 0) return tmp;
		tmp = f_rhs.compareTo(other.f_rhs);
		return tmp;
	}
}

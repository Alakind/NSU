// HASH COLLISIONS: YES
// timestamp: 1.638268271282E12

package ex10;

import com.area9innovation.flow.*;

public class Struct_ArVar extends Struct {
	public String f_name;

	public Struct_ArVar() {}
	public Struct_ArVar(String a_name) {
		f_name = a_name;
	}

	public int getTypeId() { return 15; }
	public String getTypeName() { return "ArVar"; }

	private static final String[] field_names = new String[] {
		"name"
	};
	private static final RuntimeType[] field_types = new RuntimeType[] {
		RuntimeType.STRING
	};
	public String[] getFieldNames() { return field_names; }
	public RuntimeType[] getFieldTypes() { return field_types; }

	public Object[] getFields() {
		return new Object[] {
			f_name
		};
	}
	@SuppressWarnings("unchecked")
	public void setFields(Object[] values) {
		if (values.length != 1)
			throw new IndexOutOfBoundsException("Invalid field count in ArVar");
		f_name = (String)values[0];
	}

	public int compareTo(Struct other_gen) {
		if (other_gen == this) return 0;
		int tmp = other_gen.getTypeId();
		if (tmp != 15) return 15-tmp;
		Struct_ArVar other = (Struct_ArVar)other_gen;
		tmp = f_name.compareTo(other.f_name);
		return tmp;
	}
}

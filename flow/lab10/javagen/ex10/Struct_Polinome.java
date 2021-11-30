// HASH COLLISIONS: YES
// timestamp: 1.638268271324E12

package ex10;

import com.area9innovation.flow.*;

public class Struct_Polinome extends Struct {
	public Struct f_monomes;

	public Struct_Polinome() {}
	public Struct_Polinome(Struct a_monomes) {
		f_monomes = a_monomes;
	}

	public int getTypeId() { return 96; }
	public String getTypeName() { return "Polinome"; }

	private static final String[] field_names = new String[] {
		"monomes"
	};
	private static final RuntimeType[] field_types = new RuntimeType[] {
		RuntimeType.STRUCT
	};
	public String[] getFieldNames() { return field_names; }
	public RuntimeType[] getFieldTypes() { return field_types; }

	public Object[] getFields() {
		return new Object[] {
			f_monomes
		};
	}
	@SuppressWarnings("unchecked")
	public void setFields(Object[] values) {
		if (values.length != 1)
			throw new IndexOutOfBoundsException("Invalid field count in Polinome");
		f_monomes = (Struct)values[0];
	}

	public int compareTo(Struct other_gen) {
		if (other_gen == this) return 0;
		int tmp = other_gen.getTypeId();
		if (tmp != 96) return 96-tmp;
		Struct_Polinome other = (Struct_Polinome)other_gen;
		tmp = f_monomes.compareTo(other.f_monomes);
		return tmp;
	}
}

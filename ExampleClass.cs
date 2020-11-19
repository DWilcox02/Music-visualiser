using UnityEngine;
using System.Collections;

public class ExampleClass : MonoBehaviour
{
    public ArduinoToCubes atc;
    float lastTime = 0f;
    float currentTime = 0f;
    ArrayList<float> values = new ArrayList<float>();

    void FixedUpdate()
    {
        currentTime += time.deltaTime;
        float value = atc.GetFloat(); // will have to create GetFloat method later and adjust structure
        values.Add(value);
        if(currentTime - lastTime > 0.25)
        {
            float elIndexF = 0.25 * values.Size();
            int elIndex = Convert.ToInt32(elIndexF); // might have to change formatting later
            values.RemoveRange(0, elIndex);
        }
        FindMin(values);

    }

    public float FindMin(ArrayList<float> values)
    {
        float min = values[0];
        foreach(float value in values)
        {
            if(value < min)
            {
                min = value;
            }
        }
        return min;
    }
}
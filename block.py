from blockdiag import Diagram, Node

def create_noodle_factory_diagram():
    diagram = Diagram("Noodle Manufacturing Factory")

    with diagram:
        raw_materials = Node("Raw Material Handling")
        mixing_kneading = Node("Mixing and Kneading")
        extrusion_shaping = Node("Extrusion and Shaping")
        steaming_drying = Node("Steaming or Drying")
        cooling_sorting = Node("Cooling and Sorting")
        packaging = Node("Packaging")
        quality_control = Node("Quality Control")
        storage_distribution = Node("Storage and Distribution")
        utilities = Node("Utilities")
        waste_management = Node("Waste Management")

        raw_materials >> mixing_kneading
        mixing_kneading >> extrusion_shaping
        extrusion_shaping >> steaming_drying
        steaming_drying >> cooling_sorting
        cooling_sorting >> packaging
        packaging >> quality_control
        quality_control >> storage_distribution
        utilities >> steaming_drying
        utilities >> packaging
        utilities >> cooling_sorting
        waste_management >> steaming_drying

    return diagram

if __name__ == "__main__":
    diagram = create_noodle_factory_diagram()
    diagram.format = "png"  # Output format (PNG, SVG, PDF, etc.)
    diagram.filename = "noodle_factory_diagram"
    diagram.draw()
